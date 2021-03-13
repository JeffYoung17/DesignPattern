/**
 * 抽象的做法
 * ；与MainForm1相比:只需要改动2处,而前者需要改动4处
 */
class MainForm : public Form {
private:
	Point p1;
	Point p2;

	//针对所有形状
  // 需要多态性,存放的是基类指针,希望将来指向的是Line或者Rect类型
	vector<Shape*> shapeVector;

public:
	MainForm(){
		//...
	}
protected:

	virtual void OnMouseDown(const MouseEventArgs& e);
	virtual void OnMouseUp(const MouseEventArgs& e);
	virtual void OnPaint(const PaintEventArgs& e);
};

void MainForm::OnMouseDown(const MouseEventArgs& e){
	p1.x = e.X;
	p1.y = e.Y;

	//...
	Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs& e){
	p2.x = e.X;
	p2.y = e.Y;

	if (rdoLine.Checked){
		shapeVector.push_back(new Line(p1,p2)); // new 存放的是堆对象的指针
    // 注意,在MainForm析构时，需要释放shapeVector中存放的指向堆对象的指针
	}
	else if (rdoRect.Checked){
		int width = abs(p2.x - p1.x);
		int height = abs(p2.y - p1.y);
		shapeVector.push_back(new Rect(p1, width, height));
	}
	//改变
	else if (...){
		//...
		shapeVector.push_back(circle);
	}

	//...
	this->Refresh();

	Form::OnMouseUp(e);
}

void MainForm::OnPaint(const PaintEventArgs& e){

	//针对所有形状
	for (int i = 0; i < shapeVector.size(); i++){
		shapeVector[i]->Draw(e.Graphics); //多态调用，各负其责
	}

	//...
	Form::OnPaint(e);
}
