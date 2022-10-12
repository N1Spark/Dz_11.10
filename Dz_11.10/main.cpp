#include <iostream>
using namespace std;

class Transport
{
	string color;
	char* type;
	int speed;
	int fuel;
	int passenger;
public:
	Transport()
	{
		color = "";
		type = nullptr;
		speed = fuel = passenger = 0;
	}
	Transport(const char* t, string c, int s, int f, int p)
	{
		if (type != nullptr)
		{
			delete[]type;
		}
		color = c;
		type = new char[strlen(t) + 1];
		strcpy_s(type, strlen(t) + 1, t);
		speed = s;
		fuel = f;
		passenger = p;
	}
	virtual void Show()
	{
		cout << "Transport: " << type << endl;
		cout << "Color: " << color << endl;
		cout << "Speed: " << speed << " km\\h\n";
		cout << "Fuel consumption: " << fuel << " L\\100 km\n";
		cout << "Passengers: " << passenger << endl;
	}
	virtual void Init()
	{
		cout << "Transport: ";
		char* temp = new char[128];
		cin >> temp;
		if (type != nullptr)
		{
			delete[]type;
		}
		type = new char(strlen(temp) + 1);
		strcpy_s(type, strlen(temp) + 1, temp);
		delete[]temp;
		cout << "Color: ";
		cin >> color;
		cout << "Speed: ";
		cin >> speed;
		cout << "Fuel consumption: ";
		cin >> fuel;
		cout << "Passengers: ";
		cin >> passenger;
	}
	virtual int GetFuel()
	{
		return fuel;
	}
	virtual~Transport();
};

Transport::~Transport()
{
	cout << "Transport destruct\n";
	delete[]type;
}

class Plane :public Transport
{
	char* company;
public:
	Plane()
	{
		company = nullptr;
	}
	Plane(const char* t, string c, int s, int f, int p, const char* C) :Transport(t, c, s, f, p)
	{
		if (company != nullptr)
		{
			delete[]company;
		}
		company = new char[strlen(C) + 1];
		strcpy_s(company, strlen(C) + 1, C);
	}
	void Show()
	{
		Transport::Show();
		cout << "Company: " << company << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "Company: ";
		char* temp = new char[128];
		cin >> temp;
		if (company != nullptr)
		{
			delete[]company;
		}
		company = new char(strlen(temp) + 1);
		strcpy_s(company, strlen(temp) + 1, temp);
		delete[]temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Plane()
	{
		cout << "Plane Destruct\n";
		delete[]company;
	}
};

class Bicycle :public Transport
{
	int* gear;
public:
	Bicycle()
	{
		gear = nullptr;
	}
	Bicycle(const char* t, string c, int s, int f, int p, int g) :Transport(t, c, s, 0, p)
	{
		if (gear != nullptr)
		{
			delete gear;
		}
		gear = new int;
		*gear = g;
	}
	void Show()
	{
		Transport::Show();
		cout << "Gear: " << *gear << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "Gear: ";
		if (gear != nullptr)
		{
			delete gear;
		}
		gear = new int;
		int temp;
		cin >> temp;
		*gear = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Bicycle()
	{
		cout << "Cycle Destruct\n";
		delete gear;
	}
};

class Jeep :public Transport
{
	char* insurance;
public:
	Jeep()
	{
		insurance = nullptr;
	}
	Jeep(const char* t, string c, int s, int f, int p, const char* i) :Transport(t, c, s, f, p)
	{
		if (insurance != nullptr)
		{
			delete[]insurance;
		}
		insurance = new char[strlen(i) + 1];
		strcpy_s(insurance, strlen(i) + 1, i);

	}
	void Show()
	{
		Transport::Show();
		cout << "Insurance: " << insurance << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "Is there insurance? ";
		char* temp = new char[10];
		cin >> temp;
		if (insurance != nullptr)
		{
			delete[]insurance;
		}
		insurance = new char(strlen(temp) + 1);
		strcpy_s(insurance, strlen(temp) + 1, temp);
		delete[]temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Jeep()
	{
		cout << "Jeep Destruct\n";
		delete insurance;
	}
};

class Ship :public Transport
{
	int* carrying;
public:
	Ship()
	{
		carrying = nullptr;
	}
	Ship(const char* t, string c, int s, int f, int p, int C) :Transport(t, c, s, f, p)
	{
		if (carrying != nullptr)
		{
			delete carrying;
		}
		carrying = new int;
		*carrying = C;
	}
	void Show()
	{
		Transport::Show();
		cout << "Carrying: " << *carrying << "t" << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "Enter carrying: ";
		if (carrying != nullptr)
		{
			delete carrying;
		}
		carrying = new int;
		int temp;
		cin >> temp;
		*carrying = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Ship()
	{
		cout << "Ship Destruct\n";
		delete carrying;
	}
};

class Truck :public Transport
{
	int* power;
public:
	Truck()
	{
		power = nullptr;
	}
	Truck(const char* t, string c, int s, int f, int p, int P) :Transport(t, c, s, f, p)
	{
		if (power != nullptr)
		{
			delete power;
		}
		power = new int;
		*power = P;
	}
	void Show()
	{
		Transport::Show();
		cout << "Power: " << *power << " horsepower" << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "Hoow much hoursepower? ";
		if (power != nullptr)
		{
			delete power;
		}
		power = new int;
		int temp;
		cin >> temp;
		*power = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~Truck()
	{
		cout << "Truck Destruct\n";
		delete power;
	}
};

int menu1()
{
	int choose;
	cout << "1.Plane\n2.Cycle\n3.Jeep\n4.Ship\n5.Truck\n";
	cin >> choose;
	return choose;
}

int menu2()
{
	int choose;
	cout << "1.Show\n2.Show fuel consumption per 100km\n";
	cin >> choose;
	return choose;
}

int main()
{
	int choose_1 = menu1();
	Transport* Tptr = nullptr;
	switch (choose_1)
	{
	case 1:
		Tptr = new Plane();
		Tptr->Init();
		break;
	case 2:
		Tptr = new Bicycle();
		Tptr->Init();
		break;
	case 3:
		Tptr = new Jeep();
		Tptr->Init();
		break;
	case 4:
		Tptr = new Ship();
		Tptr->Init();
		break;
	case 5:
		Tptr = new Truck();
		Tptr->Init();
		break;
	default:
		break;
	}
	system("cls");
	int choose_2 = menu2();
	switch (choose_2)
	{
	case 1:
		Tptr->Show();
		break;
	case 2:
		cout << Tptr->GetFuel();
		break;
	default:
		break;
	}
	delete Tptr;
}