/**
 * brief: 不同国家的税种计算方法
 */
enum TaxBase {
	CN_Tax,
	US_Tax,
	DE_Tax,
	FR_Tax       //更改
};

class SalesOrder{
    TaxBase tax;
public:
    double CalculateTax(){
        //...
        // 业务的变化是经常的
        // 如果是绝对的稳定:例如根据周几来进行判断,则可使用if-else或者switch
        // 否则面对需要变化的情况,可以使用策略模式
        if (tax == CN_Tax){
            //CN***********
        }
        else if (tax == US_Tax){
            //US***********
        }
        else if (tax == DE_Tax){
            //DE***********
        }
		else if (tax == FR_Tax){  //更改
			//...
		}

        //....
     }
    
};
