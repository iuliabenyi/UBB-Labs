#pragma once
#include "Validator.h"
#include "Repository.h"
//#include "Comparator.h"
#include <string>
#include <vector>
#include <exception>

using namespace std;

class Controller
{
public:
	Controller(bool = false);
	~Controller();

	bool add(T e, bool record = true);
	bool addAdoption(T e);
	bool remove(string name, bool record = true);
	bool update(string name, string newName, string breed, int age, string pic, bool record = true);
	bool nameExists(string name);
	//void sortWComparator(Comparator<T>& comp);
	vector<Dog> getFilteredDogs(string breed, int age);
	int search(string name);
	int searchDog(string &name);
	vector<Dog> &getDogs();
	vector<Dog> getAdoptions();

	void undo();
	void redo();


private:
	Repository repo;
	vector<Dog> adoption;


	class UndoOp 
	{
	public:
		UndoOp(int indxDog) : indxDog(indxDog) {}
		virtual void undo() = 0;
		int indxDog;
		virtual string getType() = 0;
		virtual Dog getDog() 
		{
			return Dog();
		}

		virtual string getNewName()
		{
			return "pl";
		}
	};

	class UndoAdd : public UndoOp {
	public:
		UndoAdd(Controller &ctrl, int indxDog, Dog dog) : UndoOp(indxDog), ctrl{ ctrl }, indxDog{ indxDog }, dog(dog) {}
		void undo() override 
		{
			ctrl.remove(dog.getName(), false);
		}

		string getType() override
		{
			return "add";
		}

		Dog getDog() override
		{
			return dog;
		}

	private:
		Controller &ctrl;
		int indxDog;
		Dog dog;

	};

	class UndoRemove : public UndoOp {
	public:
		UndoRemove(Controller &ctrl, Dog dog) : UndoOp(ctrl.searchDog(dog.getName())), ctrl{ ctrl }, dog(dog) {}
		void undo() override 
		{
			ctrl.add(dog, false);
		}

		string getType() override
		{
			return "remove";
		}

		Dog getDog() override
		{
			return dog;
		}

	private:
		Controller & ctrl;
		Dog dog;
	};

	class UndoUpdate : public UndoOp {
	public:
		UndoUpdate(Controller &ctrl, Dog dog, string name) : UndoOp(ctrl.searchDog(dog.getName())), ctrl{ ctrl }, dog(dog), name{ name } {}
		void undo() override
		{
			ctrl.update(name, dog.getName(), dog.getBreed(), dog.getAge(), dog.getPic(), false);
		}

		string getType() override
		{
			return "update";
		}

		Dog getDog() override
		{
			return dog;
		}

		string getNewName() override
		{
			return name;
		}

	private:
		string name;
		Controller & ctrl;
		Dog dog;
		
	};

	vector<UndoOp*> undoOperations;
	vector<UndoOp*> redoOperations;
	
};

