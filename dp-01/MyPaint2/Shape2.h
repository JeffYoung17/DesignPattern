class Shape{
public:
  // 含纯虚函数的类称为抽象类,只能作为基类使用,不能创建实例
	virtual void Draw(const Graphics& g)=0;
  // 虚析构,通过基类指针进行内存释放,避免可能存在的内存泄露
	virtual ~Shape() { } 
};


class Point{
public:
	int x;
	int y;
};

class Line: public Shape{
public:
  Point start;
	Point end;

	Line(const Point& start, const Point& end){
		this->start = start;
		this->end = end;
	}

	//实现自己的Draw，负责画自己
	virtual void Draw(const Graphics& g){
		g.DrawLine(Pens.Red, 
			start.x, start.y, end.x, end.y);
	}

};

class Rect: public Shape{
public:
	Point leftUp;
	int width;
	int height;

	Rect(const Point& leftUp, int width, int height){
		this->leftUp = leftUp;
		this->width = width;
		this->height = height;
	}

	//实现自己的Draw，负责画自己
	virtual void Draw(const Graphics& g){
		g.DrawRectangle(Pens.Red,
			leftUp,width,height);
	}

};

//需求的改变: 增加circle类
class Circle : public Shape{
public:
	//实现自己的Draw，负责画自己
	virtual void Draw(const Graphics& g){
		g.DrawCircle(Pens.Red,
			...);
	}

};
