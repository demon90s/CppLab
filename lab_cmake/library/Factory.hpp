// 工厂模板类，使用用户注册的创建方法来创建对象
#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <map>
#include <string>
#include <type_traits>
#include <exception>

namespace detail
{
// base class ，提供基本的工厂方法，用于注册创建方法（一个可调用对象）
template<typename CreateObject>
class BaseFactory {
	typedef std::map<std::string, CreateObject> CreateObjectMap;
	typedef typename CreateObjectMap::value_type CreateObjectPair;
	typedef typename CreateObjectMap::const_iterator CreateObjectConstIter;
public:
	// 公共接口，注册
	void RegisterObject(const std::string &obj, const CreateObject &functor) {
		bool ret = this->DoRegisterObject(obj, functor);
		if (!ret)
			throw std::runtime_error("factory_base::BaseFactory::RegisterObject fail to regist object " + obj);
	}

	// 公共接口，注销
	void UnRegisterObject(const std::string &obj) {
		bool ret = this->DoUnRegisterObject(obj);
		if (!ret)
			throw std::runtime_error("factory_base::BaseFactory::UnRegisterObject fail to unregist object " + obj);
	}

protected:
	CreateObjectMap m_create_obj_map;

	// 获取可调用对象
	CreateObjectConstIter Retrieve(const std::string &obj) const {
		auto it = m_create_obj_map.find(obj);
		if (it == m_create_obj_map.end()) {
			throw std::runtime_error("factory_base::BaseFactory::Retrieve none exist object: " + obj);
		}
		return it;
	}

private:
	// 注册可调用对象
	bool DoRegisterObject(const std::string &obj, const CreateObject &functor) {
		return m_create_obj_map.insert(CreateObjectPair(obj, functor)).second;
	}

	// 注销可调用对象
	bool DoUnRegisterObject(const std::string &obj) {
		return m_create_obj_map.erase(obj) == 1;
	}
};
}

// 工厂类，使用 Create 接口创建对象
template <typename CreateObject>
class Factory final : public detail::BaseFactory<CreateObject> {
public:
	template<typename... Args>
	typename std::result_of<CreateObject(Args...)>::type
	Create(const std::string &obj, Args... args) const {
		return (this->Retrieve(obj)->second)(args...);
	}
};

#endif // FACTORY_HPP
