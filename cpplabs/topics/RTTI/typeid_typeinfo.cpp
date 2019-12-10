/*
	RTTI 提供的其中一个运算符是 typeid(expr) 它向表达式提问: 你的对象是什么类型?

	expr 可以是任意表达式或类型的名字, 其操作结果是一个 const typeinfo&

	当运算对象不属于类类型或者是一个不包含任何虚函数的类时, typeid 运算符指示的是运算对象的静态类型.
	否则 typeid 的结果在运行时得到.

	typeinfo 支持下面的操作:
	t1 == t2 如果两者表示同一种类型, 返回 true, 否则返回 false
	t1 != t2 如果两者表示不同的类型, 返回 true, 否则返回 false
	t.name() 返回一个C风格的字符串, 表示类型名字的可打印形式, 不同系统生成方式不一样
*/

#include <typeinfo>
#include <cstdio>

void func() {}
void test1()
{
	printf("value of func: %p\n", func);
	printf("value of &func: %p\n", &func);
	printf("value of *func: %p\n", *func);

	printf("typename of func: %s\n", typeid(func).name());
	printf("typename of &func: %s\n", typeid(&func).name());
	printf("typename of *func: %s\n", typeid(*func).name());
}

// 一个静态类型
class Foo {
public:
	Foo() { printf("Foo::Foo()\n"); }
};

void test2()
{
	printf("%s\n", typeid(Foo()).name());			// 静态类型, 不会真的执行表达式(编译期得到结果)
}

void test3()
{
	class Base { public: virtual ~Base() {} };
	class Derived : public Base {};

	Base *p = new Derived();

	printf("%s\n", typeid(*p).name());	// xxxDerived 因基类有虚函数，得到实际的子类型

	delete p;
}

enum class Week
{
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

enum WEEK
{
	SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

void test4()
{
	// 测试一些平凡类型
	int number;
	printf("number: %s\n", typeid(number).name());

	printf("enum class Sunday: %s\n", typeid(Week::Sunday).name());	// 输出 Week

	printf("enum Sunday: %s\n", typeid(SUNDAY).name());	// 输出 WEEK
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}
