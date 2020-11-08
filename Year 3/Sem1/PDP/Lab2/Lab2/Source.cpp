#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>

using namespace std;

int sum = 0;
mutex mtx;
condition_variable var;
int product;
bool ready = false;
bool done = false;

tuple<vector<int>, vector<int>> vectorsTuple() {
	int n;
	cout << "n = ";
	cin >> n;
	cout << "\nVector 1\n";
	vector<int>* v1 = new vector<int>();
	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << ": ";
		int el;
		cin >> el;
		v1->push_back(el);
	}
	cout << "\nVector 2\n";
	vector<int>* v2 = new vector<int>();
	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << ": ";
		int el;
		cin >> el;
		v2->push_back(el);
	}
	return make_tuple(*v1, *v2);
}

void consumer() {
	unique_lock<mutex> lck(mtx); // unique ownership
	var.wait(lck, [] {return ready; }); // var blocked until notified
	sum += product;
	done = true;
	lck.unlock();
	var.notify_one(); // var notified
}

void producer(int i, int j) {
	unique_lock<mutex> lck(mtx);
	product = i * j;
	ready = true;
	var.notify_one();
}

int main()
{
	thread p;
	thread c;
	vector<int> v1;
	vector<int> v2;

	tie(v1, v2) = vectorsTuple();
	for (int i = 0; i < v1.size(); i++) {
		thread p(producer, v1[i], v2[i]);
		thread c(consumer);
		p.join();
		c.join();
		ready = false;
		done = false;
	}

	cout << "\nv1 x v2 = " << sum << "\n";
}

