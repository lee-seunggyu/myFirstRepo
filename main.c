#include <iostream>

using namespace std;

class Shape {
    Shape* next;
protected:
    virtual void draw();
public:
    Shape() {next = NULL;}
    virtual ~Shape() {}
    void paint();
    Shape* add(Shape* p);
    Shape* getNext() { return next;}
};

void Shape::paint() {
    draw();
}
void Shape::draw() {
    cout << "Shape" << endl;
}

Shape* Shape::add(Shape *p) {
    this->next = p;
    return p;
}

class Circle : public Shape {
protected:
    virtual void draw();
};
void Circle::draw() {
    cout << "Circle" << endl;
}

class Rect : public Shape {
protected:
    virtual void draw();
};
void Rect::draw() {
    cout << "Rectangle" << endl;
}

class Line : public Shape {
protected:
    virtual void draw();
};

void Line::draw() {
    cout << "Line" << endl;
}

int main() {

    Shape *pStart=NULL; //클래스 Shape에 대한 포인터 객체 pStart 생성 및 NULL값으로 초기화
    Shape *pLast;   //클래스 Shape에 대한 포인터 객체 pLast를 생성
    pStart = new Circle();  //pStart가 첫번째로 가리키는 값을 Circle객체로 지정
    pLast = pStart;  //pStart를 pLast에 전달
    
//    while(true)
//    {
//        string tmp;
//
//        cout << "Circle, Line, Rect 중 1가지 선택하세요 (0을 입력하면 더이상 입력받지 않습니다.) : ";
//        cin >> tmp;
//
//        if(tmp == "Circle") {
//            pLast = pLast->add(new Circle());
//        }
//        else if(tmp == "Rect") {
//            pLast = pLast->add(new Rect());
//        }
//        else if(tmp == "Line") {
//            pLast = pLast->add(new Line());
//        }
//        else if(tmp == "0") break;
//        else cout << "입력이 옳바르지 않습니다.";
//    }
    pLast = pLast->add(new Rect()); //pLast의 다음 next가 새로 생성한 Rect객체를 가리킴
    pLast = pLast->add(new Circle());   //다음 next가 새로 생성한 Circle 객체를 가리킴
    pLast = pLast->add(new Line());   //다음 next가 새로 생성한 Line객체를 가리킴
    pLast = pLast->add(new Rect());   //다음 next가 새로 생성한 Rect객체를 가리킴

    
    Shape* p = pStart;   //포인터 객체 p가 pStart 즉, Circle을 가리키도록 초기화
    while(p != NULL) {   //p가 가리키는 값이 더이상 없을때까지 즉, Rect를 가리킬때까지
        p->paint();   //p가 가리키는 객체의 paint()함수를 호출
        p = p->getNext();   //p가 가리키는 값을 다음 객체로 설정
   }

    p = pStart;   //다시 p가 가리키는 값을 첫번째 객체인 Circle로 초기화
    while(p != NULL) {   //p가 가리키는 값이 없을때까지
        Shape* q = p->getNext();   //q에 의 2번째 객체 전달
        delete p;   //p의 1번째 객체 소멸
        p = q;   //p가 가리키는 2번째 객체를 1번째 객체로 이동
    }
}
