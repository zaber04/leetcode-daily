int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(m);

        while (i <= n) {
            while ((i <= n) && !(!(i % 3) && (i % 5))) {
                cv.wait(lock);
            }

            if (i <= n) {
                printFizz();
                ++i;
            }

            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(m);

        while (i <= n) {
            while ((i <= n) && !((i % 3) && !(i%5))) {
                cv.wait(lock);
            }

            if (i <= n) {
                printBuzz();
                ++i;
            }

            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(m);

        while (i <= n) {
            while ((i <= n) && (i % 15)) {
                cv.wait(lock);
            }

            if (i <= n) {
                printFizzBuzz();
                ++i;
            }

            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);

        while (i <= n) {
            while ((i <= n) && !((i % 3) && (i % 5))) {
                cv.wait(lock);
            }

            if (i <= n) {
                printNumber(i);
                ++i;
            }

            cv.notify_all();
        }
    }
};