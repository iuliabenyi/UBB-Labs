#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include <queue>

using namespace std;

int sum = 0;
mutex mtx;
condition_variable var;
int result = 0;
std::queue<int> coada;

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

void producer (vector<int> v1, vector<int> v2) {
	for (int i = 0; i < v1.size(); i++) {
		unique_lock<mutex> lck(mtx);
		while(!coada.empty())
		{
			var.wait(lck);
		}
		int prod = v1[i] * v2[i];
		coada.emplace(prod);
		var.notify_one();
	}
}

void consumer(int n) {
	for(int i = 0; i < n; i++) {
		unique_lock<mutex> lck(mtx);
		while (coada.empty())
		{
			var.wait(lck);
		}
		int prod = coada.front();
		coada.pop();
		sum += prod;
		lck.unlock();
		var.notify_one();
	}
}

int main()
{
	vector<int> v1;
	vector<int> v2;

	tie(v1, v2) = vectorsTuple();
	thread p(producer, v1, v2);
	thread c(consumer, v1.size());
	p.join();
	c.join();
	
	
	

	cout << "\nv1 x v2 = " << sum << "\n";
}

