/**
 * brief: ��ͬ���ҵ�˰�ּ��㷽��
 */
enum TaxBase {
	CN_Tax,
	US_Tax,
	DE_Tax,
	FR_Tax       //����
};

class SalesOrder{
    TaxBase tax;
public:
    double CalculateTax(){
        //...
        // ҵ��ı仯�Ǿ�����
        // ����Ǿ��Ե��ȶ�:��������ܼ��������ж�,���ʹ��if-else����switch
        // ���������Ҫ�仯�����,����ʹ�ò���ģʽ
        if (tax == CN_Tax){
            //CN***********
        }
        else if (tax == US_Tax){
            //US***********
        }
        else if (tax == DE_Tax){
            //DE***********
        }
		else if (tax == FR_Tax){  //����
			//...
		}

        //....
     }
    
};
