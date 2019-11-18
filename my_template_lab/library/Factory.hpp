// ����ģ���࣬ʹ���û�ע��Ĵ�����������������
#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <map>
#include <string>
#include <type_traits>
#include <exception>

namespace detail
{
// base class ���ṩ�����Ĺ�������������ע�ᴴ��������һ���ɵ��ö���
template<typename CreateObject>
class BaseFactory {
	typedef std::map<std::string, CreateObject> CreateObjectMap;
	typedef typename CreateObjectMap::value_type CreateObjectPair;
	typedef typename CreateObjectMap::const_iterator CreateObjectConstIter;
public:
	// �����ӿڣ�ע��
	void RegisterObject(const std::string &obj, const CreateObject &functor) {
		bool ret = this->DoRegisterObject(obj, functor);
		if (!ret)
			throw std::runtime_error("factory_base::BaseFactory::RegisterObject fail to regist object " + obj);
	}

	// �����ӿڣ�ע��
	void UnRegisterObject(const std::string &obj) {
		bool ret = this->DoUnRegisterObject(obj);
		if (!ret)
			throw std::runtime_error("factory_base::BaseFactory::UnRegisterObject fail to unregist object " + obj);
	}

protected:
	CreateObjectMap m_create_obj_map;

	// ��ȡ�ɵ��ö���
	CreateObjectConstIter Retrieve(const std::string &obj) const {
		auto it = m_create_obj_map.find(obj);
		if (it == m_create_obj_map.end()) {
			throw std::runtime_error("factory_base::BaseFactory::Retrieve none exist object: " + obj);
		}
		return it;
	}

private:
	// ע��ɵ��ö���
	bool DoRegisterObject(const std::string &obj, const CreateObject &functor) {
		return m_create_obj_map.insert(CreateObjectPair(obj, functor)).second;
	}

	// ע���ɵ��ö���
	bool DoUnRegisterObject(const std::string &obj) {
		return m_create_obj_map.erase(obj) == 1;
	}
};
}

// �����࣬ʹ�� Create �ӿڴ�������
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
