#include<iostream>
using namespace std;

template <class T>
class Calculator{
private:
	T m_n1, m_n2;
public:
	Calculator(T n1, T n2){
		m_n1 = n1;
		m_n2 = n2;
	}
	void displayResult(){
		cout<<"Numbers: "<<m_n1<<" and "<<m_n2<<"."<<endl;
		cout << m_n1 << " + " << m_n2 << " = " << add() << endl;
        cout << m_n1 << " - " << m_n2 << " = " << subtract() << endl;
        cout << m_n1 << " * " << m_n2 << " = " << multiply() << endl;
        cout << m_n1 << " / " << m_n2 << " = " << divide() << endl;
	}

	T add(){ return m_n1+m_n2;}
	T subtract(){ return m_n1-m_n2;}
	T multiply(){ return m_n1+m_n2;}
	T divide(){return m_n1/m_n2; }
};

int main(){
	Calculator<int> intCalc(2,1);
	Calculator<float> floatCalc(2.4, 1.2);
	cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl
         << "Float results:" << endl;
    floatCalc.displayResult();
}