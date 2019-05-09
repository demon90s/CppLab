#ifndef __OBJECT_POOL_HPP__
#define __OBJECT_POOL_HPP__

/*
	�򵥵��ڴ�أ����Ի���Obj���ظ�����֮
*/
#include <memory>
#include <stack>
#include <stdexcept>

template <typename T>
class ObjectPool
{
    template<typename M>
	class PooledObject
	{
        friend class ObjectPool<M>;
        ObjectPool<M> *pool = nullptr;
        M *object = nullptr;
	public:
        M& operator*() { return *object; }
        M* operator->() { return &this->operator*(); }
	};
public:
	using Object = PooledObject<T>;

	ObjectPool() {}
	~ObjectPool()
	{
		while (unconstructed_objects.size() > 0)
		{
			auto pooled_obj = unconstructed_objects.top();
			unconstructed_objects.pop();

			alloc.deallocate(pooled_obj.object, 1);
		}
	}

	// ����һ��ʵ��
	Object GetPooledObject()
	{
		Object pooled_obj;
		if (unconstructed_objects.size() > 0)
		{
			pooled_obj = unconstructed_objects.top();
			unconstructed_objects.pop();
		}
		else
		{
			T *object = alloc.allocate(1);
			pooled_obj.pool = this;
			pooled_obj.object = object;
		}

		alloc.construct(pooled_obj.object);
		return pooled_obj;
	}

	// ��ʵ�����س���
	void ReturnPooledObject(Object to_return)
	{
		if (to_return.pool != this)
		{
			throw std::runtime_error("ObjectPool::ReturnPooledObject, wrong object to return");
		}

		alloc.destroy(to_return.object);
		unconstructed_objects.push(to_return);
	}

private:
	// no copy
	ObjectPool(const ObjectPool&) = delete;
	ObjectPool& operator=(const ObjectPool&) = delete;

	std::allocator<T> alloc;

	std::stack<Object> unconstructed_objects;
};

#endif // __OBJECT_POOL_HPP__
