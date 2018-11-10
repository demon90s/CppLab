#ifndef __OBJECT_POOL_HPP__
#define __OBJECT_POOL_HPP__

/*
	�򵥵��ڴ�أ����Ի���Obj���ظ�����֮
*/
#include <memory>
#include <stack>
#include <stdexcept>

template<typename> class ObjectPool;

template<typename T>
class PooledObject
{
public:
	ObjectPool<T> *pool = nullptr;
	T *object = nullptr;
};

template <typename T>
class ObjectPool
{
public:
	ObjectPool() {}
	~ObjectPool()
	{
		while (unconstructed_objects.size() > 0)
		{
			auto pooled_obj = unconstructed_objects.top();
			unconstructed_objects.pop();

			alloc.deallocate(pooled_obj->object, 1);
			delete pooled_obj;
		}
	}

	// ���س��е�һ��ʵ��
	PooledObject<T>* GetPooledObject()
	{
		PooledObject<T> *pooled_obj = nullptr;
		if (unconstructed_objects.size() > 0)
		{
			pooled_obj = unconstructed_objects.top();
			unconstructed_objects.pop();
		}
		else
		{
			T *object = alloc.allocate(1);
			pooled_obj = new PooledObject<T>();
			pooled_obj->pool = this;
			pooled_obj->object = object;
		}

		alloc.construct(pooled_obj->object);
		return pooled_obj;
	}

	// ��ʵ�����س���
	void ReturnPooledObject(PooledObject<T> *to_return)
	{
		if (to_return->pool != this)
		{
			throw std::runtime_error("ObjectPool::ReturnObject, wrong object to return");
		}

		alloc.destroy(to_return->object);
		unconstructed_objects.push(to_return);
	}

private:
	// no copy
	ObjectPool(const ObjectPool&) = delete;
	ObjectPool& operator=(const ObjectPool&) = delete;

	std::allocator<T> alloc;
	std::stack<PooledObject<T>*> unconstructed_objects;
};

#endif // __OBJECT_POOL_HPP__