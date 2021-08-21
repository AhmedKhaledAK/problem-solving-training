class Foo {
    atomic<int> printed{0};
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        printed.fetch_add(1);
    }

    void second(function<void()> printSecond) {
        while (printed.load() != 1)
        {
            this_thread::yield();
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        printed.fetch_add(1);
    }

    void third(function<void()> printThird) {
        while (printed.load() != 2)
        {
            this_thread::yield();
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
