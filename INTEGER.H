//** This Header File Designed & Developed By 'Kishan Vaishnav' Year 2021 **//

#ifndef IOSTREAM_H
#include<iostream.h>
#endif
#ifndef CONIO_H
#include<conio.h>
#endif
#ifndef INTEGER_H
#define INTEGER_H
#endif

enum bool
{
	false=0,true=1
};

class Queue
{
    friend class INTEGER; // Direct Access By INTEGER Class //
    private:
	char*ptr;
	int capacity;
	int status;
	int start_index;
    public:
	Queue(int capacity);
       ~Queue();
	void enQueue(char item);
	void printQueue();
	char deQueue();
	bool isZeroQueue();
	void deleteQueue();
	inline int getCapacity();
	inline int getStatus();
	inline bool isEmpty();
	inline bool isFull();
};

Queue::Queue(int capacity)
{
    this->capacity=capacity;
    start_index=status=-1;
    ptr=new char[capacity];
}

Queue::~Queue()
{
    delete []ptr;
    ptr=NULL;
}

void Queue::enQueue(char item)
{
    if(status!=capacity-1)
    {
	ptr[++status]=item;
    }
}

void Queue::printQueue()
{
    if(status==-1)
	cout<<"Queue is Empty : ";
    else
    {
	int i;
	for(i=0;i<=status;i++)
	    cout<<ptr[i];
    }
}

char Queue::deQueue()
{
    if(status!=-1)
    {
	status--;
	return(ptr[++start_index]);
    }
    return(48);
}

bool Queue::isZeroQueue()
{
    int i;
    for(i=0;i<=status;i++)
    {
	if(ptr[i]!=48)
	    return(false);
    }
    return(true);
}

void Queue::deleteQueue()
{
    start_index=status=-1;
}

int Queue::getCapacity()
{
    return(capacity);
}

int Queue::getStatus()
{
    return(status);
}

bool Queue::isEmpty()
{
    return(status==-1?true:false);
}

bool Queue::isFull()
{
    return(status==capacity-1?true:false);
}

/********************** Description Of INTEGER ****************************
 * Properties |	Private Methods	| Constructors | Public Methods           *
 *************|*****************|**************|***************************
 *	4     |       12        |      4       |       40                 *
 **************************************************************************
 *                      Input And Output Macanisum                        *
 **************************************************************************
 *         Input                     |             Output                 *
 ************************************|*************************************
 * For Input We Overload Attraction  |  For Ouput We  Overload  Insertion *
 * >> Operator With Friend Function  |  << Operator  With Friend Function *
 * Concept . To Look Like Primitive  |  Concept . To Look Like  Primitive *
 * Data Type . And  Easy  To Use By  |  Data Type.And Easy To Use By User.*
 * User.                             |                                    *
 **************************************************************************/

class INTEGER
{
    private:
	char*IPTR;
	char sign;
	int status;
	int SIZE;
	inline int toInteger(char ch);
	void _add(INTEGER&i2,INTEGER&result);
	void _sub(INTEGER&i2,INTEGER&result);
	void _multi(INTEGER&i2,INTEGER&result);
	void _division(INTEGER&i2,INTEGER&result);
	void _remainder(INTEGER&i2,INTEGER&result);
	bool _isBigWs(INTEGER&refer);
	bool _isBigWsNe(INTEGER&refer);
	void _toIncrement();
	void _toDecrement();
	bool _isGraterThanEqualTo(INTEGER&i2);
	void _subDivide(INTEGER&op1,INTEGER&counter_integer,INTEGER&m_result,INTEGER&op2,Queue&remain,Queue&temp_result);
    public:
	INTEGER(int SIZE);
	INTEGER(const INTEGER&refer);
	INTEGER(INTEGER&refer,int SIZE);
	INTEGER(int SIZE,int value);
       ~INTEGER();
	inline bool isZero();
	inline bool isFull();
	inline bool isPositive();
	inline bool isEmpty();
	inline int getSize();
	inline int getStatus();
	friend istream& operator>>(istream&,INTEGER&);
	friend ostream& operator<<(ostream&,INTEGER&);
	INTEGER operator+(INTEGER&);
	INTEGER operator-(INTEGER&);
	INTEGER operator*(INTEGER&);
	INTEGER operator/(INTEGER&);
	INTEGER operator%(INTEGER&);
	INTEGER& operator++();
	INTEGER operator++(int);
	INTEGER& operator--();
	INTEGER operator--(int);
	INTEGER operator+(const char*source);
	INTEGER operator-(const char*source);
	INTEGER operator*(const char*source);
	INTEGER operator/(const char*source);
	INTEGER operator%(const char*source);
	INTEGER& operator=(const INTEGER&);
	bool operator<(INTEGER&);
	bool operator<=(INTEGER&);
	bool operator>(INTEGER&);
	bool operator>=(INTEGER&);
	bool operator==(INTEGER&);
	bool operator!=(INTEGER&);
	bool operator<(const char*source);
	bool operator<=(const char*source);
	bool operator>(const char*source);
	bool operator>=(const char*source);
	bool operator==(const char*source);
	bool operator!=(const char*source);
	int getLengthFormat(const char*source);
	int getLength(const char*source);
	void getDetail();
	bool operator=(const char*source);
	void printFormat(char symbol,int skeep);
};

int INTEGER::toInteger(char ch)
{
    return(ch-48);
}

void INTEGER::_add(INTEGER& i2,INTEGER& result)
{
	int i,k,res=0,counts,index,lower=(status<i2.status?status:i2.status);
	i=SIZE-2;   // Represent Current String
	k=i2.SIZE-2;//Represent Second String
	counts=result.SIZE-2;
	for(index=0;index<=lower;index++)
	{
	    res=res+toInteger(IPTR[i])+toInteger(i2.IPTR[k]);
	    result.IPTR[counts]=(res%10)+48;
	    res/=10;
	    i--;
	    k--;
	    counts--;
	    result.status++;
	}
	lower=SIZE-2-status;
	while(i>=lower)
	{
	    res=res+toInteger(IPTR[i]);
	    result.IPTR[counts]=(res%10)+48;
	    res/=10;
	    i--;
	    counts--;
	    result.status++;
	}
	lower=i2.SIZE-2-i2.status;
	while(k>=lower)
	{
	    res=res+toInteger(i2.IPTR[k]);
	    result.IPTR[counts]=(res%10)+48;
	    res/=10;
	    k--;
	    counts--;
	    result.status++;
	}
	if(res==1)
	{
	    result.IPTR[0]=49;
	    result.status++;
	}
}

void INTEGER::_sub(INTEGER&i2,INTEGER&result)
{
    int base=10,lower=(status<i2.status?status:i2.status),i,k,counts,temp=0,b=0,rounds;
    i=SIZE-2;
    k=i2.SIZE-2;
    counts=result.SIZE-2;
    for(rounds=0;rounds<=lower;rounds++)
    {
	if((IPTR[i]-b)>=i2.IPTR[k])
	{
	    result.IPTR[counts]=(IPTR[i]-i2.IPTR[k]-b)+48;
	    b=0;
	}
	else
	{
	    temp=toInteger(IPTR[i]);
	    temp=temp+base-b;
	    result.IPTR[counts]=(temp-toInteger(i2.IPTR[k]))+48;
	    b=1;
	}
	i--;
	k--;
	counts--;
    }
    if(i>=SIZE-2-status && b==1)
    {
	base=9;
	while(true)
	{
	    if(IPTR[i]>48)
	    {
		result.IPTR[counts]=toInteger(IPTR[i])+47;
		i--;
		counts--;
		break;
	    }
	    else
	    result.IPTR[counts]=toInteger(IPTR[i])+base+48;
	    i--;
	    counts--;
	}
    }
    lower=SIZE-2-status;
    while(i>=lower)
    {
	    result.IPTR[counts]=IPTR[i];
	    i--;
	    counts--;
    }
    lower=result.SIZE-3;
    for(i=0;i<=lower;i++)
    {
	if(result.IPTR[i]==48)
	    result.status--;
	else
	    break;
    }
}

void INTEGER::_multi(INTEGER &i2,INTEGER &result)
{

    int lower_index=i2.status,higher_index=status,i,k,counts=result.SIZE-2,op1,op2,res=0,last_index=i2.SIZE-2,high_index=SIZE-2,second_input;
    int forward_index=0;
    for(k=0;k<=lower_index;k++)
    {
       op2=last_index-k;
       second_input=toInteger(i2.IPTR[op2]);
       for(i=0;i<=higher_index;i++)
       {
	  op1=high_index-i;
	  res=res+(toInteger(IPTR[op1])*second_input)+toInteger(result.IPTR[counts]);
	  result.IPTR[counts]=(res%10)+48;
	  res/=10;
	  counts--;
       }
       result.IPTR[counts]=res+48;
       res=0;
       forward_index++;
       counts=result.SIZE-2-forward_index;
    }
    lower_index=result.SIZE-2;
    for(i=0;i<=lower_index;i++)
    {
	if(result.IPTR[i]==48)
	    result.status--;
	else
	    break;
    }
}

void INTEGER::_division(INTEGER&i2,INTEGER&result)
{
    int last_index=SIZE-2,i;
    int round=SIZE-2-status;
    INTEGER op1(i2.status+2);
    INTEGER counter_integer(i2.status+1);
    INTEGER m_result(i2.status+2);
    Queue remain(i2.status+2);
    Queue temp_result(status+1);
    while(round<=last_index)
    {
	remain.ptr[++remain.status]=IPTR[round];
	_subDivide(op1,counter_integer,m_result,i2,remain,temp_result);
	round++;
    }
    last_index=result.SIZE-2;
    for(round=0;round<=temp_result.status;round++)
	if(temp_result.ptr[round]>=49)
	    break;
    for(i=temp_result.status;i>=round;i--)
    {
	result.IPTR[last_index]=temp_result.ptr[i];
	result.status++;
	last_index--;
    }
}

void INTEGER::_remainder(INTEGER&i2,INTEGER&result)
{
    int last_index=SIZE-2,i;
    int round=SIZE-2-status;
    INTEGER op1(i2.status+2);
    INTEGER counter_integer(i2.status+1);
    INTEGER m_result(i2.status+2);
    Queue remain(i2.status+2);
    Queue temp_result(status+1);
    while(round<=last_index)
    {
	remain.ptr[++remain.status]=IPTR[round];
	_subDivide(op1,counter_integer,m_result,i2,remain,temp_result);
	round++;
    }
    last_index=result.SIZE-2;
    for(i=remain.status;i>=0;i--)
    {
	result.IPTR[last_index]=remain.ptr[i];
	result.status++;
	last_index--;
    }
}

bool INTEGER::_isBigWs(INTEGER&refer)
{
     int i=SIZE-2-status,k=refer.SIZE-2-refer.status,lower=(status<refer.status?status:refer.status),round;
     if(status>refer.status)
	return(true);
     else if(status<refer.status)
	return(false);
     else
     for(round=0;round<=lower;round++)
     {
	 if(IPTR[i]>refer.IPTR[k])
	    return(true);
	 else if(IPTR[i]<refer.IPTR[k])
	    return(false);
	    i++;
	    k++;
     }
     return(true);
}

bool INTEGER::_isBigWsNe(INTEGER &refer)
{
     int i=SIZE-2-status,k=refer.SIZE-2-refer.status,lower=(status<refer.status?status:refer.status),round;
     if(status>refer.status)
	return(true);
     else if(status<refer.status)
	return(false);
     else
     for(round=0;round<=lower;round++)
     {
	 if(IPTR[i]>refer.IPTR[k])
	    return(true);
	 else if(IPTR[i]<refer.IPTR[k])
	    return(false);
	    i++;
	    k++;
     }
     return(false);
}

void INTEGER::_toIncrement()
{
	int i,last_index=SIZE-2-status;
	for(i=SIZE-2;i>=last_index;i--)
	{
	    if(IPTR[i]==57)
		IPTR[i]=48;
	    else
	    {
		IPTR[i]=IPTR[i]+1;
		return;
	    }
	}
	if(i>=0)
	{
	    IPTR[i]=49;
	    status++;
	}
	else
	{
	    status=0;
	}
}

void INTEGER::_toDecrement()
{
    int i,last_index=SIZE-2-status;
    for(i=SIZE-2;i>=last_index;i--)
    {
	if(IPTR[i]==48)
	    IPTR[i]=57;
	else
	{
	    if(IPTR[i]==49 && i==last_index && IPTR[i+1]==57)
	    {
		status--;
	    }
	    IPTR[i]=IPTR[i]-1;
	}
    }
}

bool INTEGER::_isGraterThanEqualTo(INTEGER&i2)
{
    if(status<i2.status)
	return(true);
    else if(status>i2.status)
	return(false);
    else
    {
	int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
	bool result;
	for(round=0;round<=last_index;round++)
	{
	    if(IPTR[i]<i2.IPTR[k])
		return(true);
	    else if(IPTR[i]==i2.IPTR[k])
		result=true;
	    else
		return(false);
		i++;
		k++;
	}
	return(result);
    }
}

void INTEGER::_subDivide(INTEGER&op1,INTEGER&counter,INTEGER&m_result,INTEGER&op2,Queue&remain,Queue&temp_result)
{
    op1.status=remain.status;
    int index=op1.SIZE-2,i=0,k,counter_start_index,m_result_start_index;
    while(remain.status>=0)
    {
	op1.IPTR[index]=remain.ptr[remain.status];
        index--;
        remain.status--;
    }
    remain.status=op1.status;
    if(op2._isGraterThanEqualTo(op1))
    {
        counter.IPTR[counter.SIZE-2]=48;
        m_result.IPTR[m_result.SIZE-2]=48;
        m_result.status=counter.status=0;
	while(m_result<=op1)
        {
            counter._toIncrement();
            m_result=op2*counter;
        }
	if(m_result>op1)
        {
            m_result=m_result-op2;
            counter._toDecrement();
        }
	counter_start_index=counter.SIZE-2-counter.status;
        for(i=0;i<=counter.status;i++)
            temp_result.ptr[++temp_result.status]=counter.IPTR[counter_start_index+i];

        m_result=op1-m_result;
        m_result_start_index=m_result.SIZE-2-m_result.status;
        remain.start_index=remain.status=-1;
        if(!m_result.isZero())
            for(i=0;i<=m_result.status;i++)
                remain.ptr[++remain.status]=m_result.IPTR[m_result_start_index+i];
    }
    else
    {
        if(remain.isZeroQueue())
            remain.status=-1;
	temp_result.ptr[++temp_result.status]=48;
        op1.status=-1;
    }
}

INTEGER::INTEGER(int SIZE)
{
    IPTR=NULL;
    sign=43;    // ASCII Value of "+" //
    this->SIZE=SIZE+1;
    IPTR=new char[this->SIZE];
    status=-1;
    IPTR[SIZE]='\0';
}

INTEGER::INTEGER(const INTEGER&refer)
{
    int last_index=refer.SIZE-1;
    IPTR=NULL;
    sign=refer.sign;
    SIZE=refer.SIZE;
    status=refer.status;
    IPTR=new char[SIZE];
    int i;
   for(i=refer.SIZE-2-refer.status;i<=last_index;i++)
	IPTR[i]=refer.IPTR[i];
}

INTEGER::INTEGER(INTEGER &refer,int Size)
{
    int i,op1,op2;
    IPTR=NULL;
    sign=refer.sign;
    SIZE=Size+1;
    IPTR = new char[SIZE];
    if(SIZE-2<=refer.status)
        status=SIZE-2;
    else
        status=refer.status;
    op1=SIZE-2-status;
    op2=refer.SIZE-2-refer.status;
    for(i=0;i<=status;i++)
    {
        IPTR[op1]=refer.IPTR[op2];
        op1++;
	op2++;
    }
    IPTR[i]='\0';
}

INTEGER::INTEGER(int SIZE,int value)
{
    IPTR=NULL;
    sign=43;
    this->SIZE=SIZE+1;
    IPTR=new char[this->SIZE];
    status=SIZE-1;
    int i;
    for(i=0;i<=status;i++)
        IPTR[i]=value;
    IPTR[i]='\0';
}

INTEGER::~INTEGER()
{
    delete []IPTR;
    IPTR=NULL;
}

bool INTEGER::isZero()
{
    return(status==0&&IPTR[SIZE-2]==48?true:false);
}

bool INTEGER::isFull()
{
    return(status+1==SIZE-1?true:false);
}

bool INTEGER::isPositive()
{
    return(sign=='+'?true:false);
}

bool INTEGER::isEmpty()
{
    return(status==-1?true:false);
}

int INTEGER::getSize()
{
    return(SIZE-1);
}

int INTEGER::getStatus()
{
    return(status+1);
}

istream& operator>>(istream&input,INTEGER&i2)
{

        int i=-1,ch;
        bool ok=false;  // For Only One Time Input as 0 //
        while(true)
	{
            ch=getch();
            if(i!=-1 || ch!=48)                     // First Time User Enter 0 as A Input Then Not Accepted By Input //
	    {
                if(i<i2.SIZE-2 && ch>=48 && ch<=57)
                {
                    if(ok==true)                    // If One Time 0 is Entered and Now User Enter Another Value Then //
                    {
                        i2.status--;
                        cout<<'\b';
			ok=false;                 // When User Delete Old Entered Number and Now He Entered Again 0 Value as Input //
                    }
                    i2.IPTR[++i]=char(ch);
                    i2.status++;
                    cout<<i2.IPTR[i];
		}
                else if(ch==8 && i>=0)
                {
                    cout<<'\b';
                    cout<<" ";
		    cout<<'\b';
                    i--;
                    i2.status--;
		}
                else if(ch==45 && i2.sign!=45 && i==-1 && ok==false)  // This For One Time Input '-' Operator   //
                {
                    i2.sign=45;
                    cout<<"-";
                }

		else if(ch==8 && i2.sign==45)  // This For One Time Delete '-' Operator //
                {
                     i2.sign=43;
                     cout<<'\b';
                     cout<<" ";
		     cout<<'\b';
                }

                else if(ch==8 && ok==true)  // If User Can Delete First Input 0 Value //
                {
		    cout<<'\b'<<" "<<'\b';
                    i2.status--;
                    ok=false;
		}
                else if(ch==13 && i>=0)     // Normal Values Entered Then Normal Termination //
                break;
                else if(ch==13 && ok==true) // Only Entered Value is 0 Then Normal Termination //
                break;
            }
            else if(ok==false && ch==48 && i2.sign!=45)  // User Can Only Input 0 As First Input When No Enter Negative Symbol //
	    {
                i2.IPTR[0]=48;
                ok=true;
                i2.status++;
                cout<<(char)ch;
	    }
        }
        if(!i2.isFull())    // When Normal Termination is Complete Then Arranging Number From Right To Left //
        {
                for(i=0;i<=i2.status;i++)
		{
                    i2.IPTR[(i2.SIZE-2)-i]=i2.IPTR[i2.status-i];
                }
	}
    cout<<endl;
    return(input);
}

ostream& operator<<(ostream&output,INTEGER&i1)
{
    if(i1.isEmpty())
    {
        cout<<"Empty";
        return(output);
    }
    int i,last_index=i1.SIZE-2;
    if(i1.sign==45)
        cout<<"-";
    for(i=last_index-i1.status;i<=last_index;i++)
        cout<<i1.IPTR[i];
    return(output);
}

INTEGER INTEGER::operator+(INTEGER&i2)
{
        if(i2.isEmpty() || this->isEmpty())
        {
            INTEGER temp(1);
            return(temp);
        }
	else
        {
            if(sign==43 && i2.sign==43)
            {
                INTEGER result((status>i2.status?status:i2.status)+2);
		_add(i2,result);
                return(result);
            }
            else if(sign==43 && i2.sign==45)
            {
		if(_isBigWs(i2))
                {
                    INTEGER result((status>i2.status?status:i2.status)+1);
		    result.status=result.SIZE-2;
                    _sub(i2,result);
                    return(result);
                }
                else
                {
                    INTEGER result((status>i2.status?status:i2.status)+1);
		    result.status=result.SIZE-2;
                    result.sign=45;
                    i2._sub(*this,result);
                    return(result);
                }
	    }
            else if(sign==45 && i2.sign==43)
            {
                if(_isBigWsNe(i2))
                {
		    INTEGER result((status>i2.status?status:i2.status)+1);
                    result.status=result.SIZE-2;
                    result.sign=45;
		    _sub(i2,result);
                    return(result);
                }
                else
                {
                    INTEGER result((status>i2.status?status:i2.status)+1);
                    result.status=result.SIZE-2;
		    i2._sub(*this,result);
                    return(result);
                }
            }
            else
	    {
                INTEGER result((status>i2.status?status:i2.status)+2);
                _add(i2,result);
                result.sign=45;
                return(result);
	    }
        }
}

INTEGER INTEGER::operator-(INTEGER&i2)
{
        if(i2.isEmpty()||this->isEmpty())
        {
            INTEGER temp(1);
            return(temp);
	}
        else
        {
            if(sign==43 && i2.sign==45)
            {
		if(isZero())
                    return(i2);
                INTEGER result((status>i2.status?status:i2.status)+2);
                _add(i2,result);
                return(result);
	    }
            else if(sign==45 && i2.sign==43)
            {
		if(i2.isZero())
                    return(*this);
                INTEGER result((status>i2.status?status:i2.status)+2);
                _add(i2,result);
                result.sign=45;
                return(result);
            }
	    else if(sign==43 && i2.sign==43)
            {
                if(isZero() && i2.isZero())
                    return(*this);
                if(isZero())
		{
                    INTEGER result(i2,i2.status+1);
                    result.sign=45;
                    return(result);
                }
		if(i2.isZero())
                    return(*this);
                if(*this>i2)
		{
                    INTEGER result((status>i2.status?status:i2.status)+1);
                    result.status=result.SIZE-2;;
                    _sub(i2,result);
                    return(result);
                }
                else if(*this<i2)
		{
                    INTEGER result((status>i2.status?status:i2.status)+1);
                    result.status=result.SIZE-2;
                    i2._sub((*this),result);
                    result.sign=45;
		    return(result);
                }
                else
                {
                    INTEGER result(1);
		    result.IPTR[0]=48;
                    result.status=0;
                    return(result);
		}
            }
            else
            {
                if(*this>i2)
                {
                    INTEGER result((status>i2.status?status:i2.status)+1);
		    result.status=result.SIZE-2;
                    i2._sub((*this),result);
                    return(result);
                }
                else if(*this<i2)
		{
                    INTEGER result((status>i2.status?status:i2.status)+1);
                    result.status=result.SIZE-2;
                    _sub(i2,result);
                    result.sign=45;
		    return(result);
                }
                else
		{
                    INTEGER result(1);
                    result.IPTR[0]=48;
                    result.status=0;
                    return(result);
                }
            }
	}
}

INTEGER INTEGER::operator*(INTEGER &i2)
{
	if(i2.isEmpty()||this->isEmpty())
        {
            INTEGER temp(1);
            return(temp);
        }
	else
        {
            if(isZero()|| i2.isZero())
	    {
                INTEGER result(1);
                result.IPTR[0]=48;
                result.status=0;
                return(result);
            }
            else
	    {
                char symbol=43;
                if(sign==45 && i2.sign==43)
                    symbol=45;
                else if(sign==43 && i2.sign==45)
		    symbol=45;
                if(_isBigWs(i2))
                {
                    INTEGER result(((status+1)*2),48);
                    _multi(i2,result);
		    result.sign=symbol;
                    return(result);
                }
		else
                {
                    INTEGER result(((i2.status+1)*2),48);
                    i2._multi(*this,result);
                    result.sign=symbol;
                    return(result);
                }
	    }
        }
}

INTEGER INTEGER::operator/(INTEGER&i2)
{
    if(isZero())
    {
        INTEGER result(1);
        result.IPTR[0]=48;
	result.status=0;
        return(result);
    }
    else if(i2.isZero())
    {
        cout<<"\nCannot Divided By Zero : ";
        INTEGER result(1);
        return(result);
    }
    else
    {
        char symbol=43,temp;
        if(sign==45 && i2.sign==43)
            symbol=45;
        else if(sign==43 && i2.sign==45)
	    symbol=45;
        if(_isBigWs(i2))
        {
            temp=i2.sign;
            i2.sign=43;
	    INTEGER result(status+1);
            _division(i2,result);
            result.sign=symbol;
	    i2.sign=temp;
            return(result);
        }
        else
        {
            INTEGER result(1);
            result.IPTR[0]=48;
	    result.status=0;
            return(result);
        }
    }
}

INTEGER INTEGER::operator%(INTEGER&i2)
{
    if(i2.isEmpty()||this->isEmpty())
    {
	INTEGER temp(1);
        return(temp);
    }
    else
    {
        if(isZero())
        {
            INTEGER result(1);
            result.IPTR[0]=48;
            result.status=0;
	    return(result);
        }
        else if(i2.isZero())
        {
            cout<<"\nResult is Undefined : ";
	    INTEGER result(1);
            return(result);
        }
        else
        {
	    char symbol=43,temp;
            if(sign==45 && i2.sign==43)
                symbol=45;
	    else if(sign==45 && i2.sign==45)
                symbol=45;
            if(_isBigWs(i2))
            {
                temp=i2.sign;
                i2.sign=43;
                INTEGER result(status+1);
		_remainder(i2,result);
                result.sign=symbol;
                i2.sign=temp;
                return(result);
            }
	    else
            {
                return(*this);
            }
        }
    }
}

INTEGER& INTEGER::operator++()
{
      if(isEmpty())
        return(*this);
      else
      {
            if(sign==43)
	    {
                int i,last_index=SIZE-2-status;
                for(i=SIZE-2;i>=last_index;i--)
                {
                    if(IPTR[i]==57)
			IPTR[i]=48;
                    else
                    {
                        IPTR[i]=IPTR[i]+1;
                        return(*this);
		    }
                }
                if(i>=0)
		{
                    IPTR[i]=49;
                    status++;
                    return(*this);
                }
                else
                {
		    status=0;
                    return(*this);
                }
            }
            else
	    {
                if(IPTR[SIZE-2]==49 && status==0)
                {
                    sign=43;
                    IPTR[SIZE-2]=48;
		    return(*this);
                }
                int i,last_index=SIZE-2-status;
		for(i=SIZE-2;i>=last_index;i--)
                {
                    if(IPTR[i]==48)
                        IPTR[i]=57;
                    else if(IPTR[i]==49 && i==last_index)
                    {
                        status--;
			return(*this);
                    }
                    else
                    {
                        IPTR[i]=IPTR[i]-1;
			return(*this);
                    }
                }
            }
      }
      return(*this);
}

INTEGER& INTEGER::operator--()
{
    if(isEmpty())
	return(*this);
    else
    {
	if(sign==43)
	{
	    if(status==0 && IPTR[SIZE-2]==48)
	    {
		sign=45;
		IPTR[SIZE-2]=49;
		return(*this);
	    }
	    int i,last_index=SIZE-2-status;
	    for(i=SIZE-2;i>=last_index;i--)
	    {
		if(IPTR[i]==48)
		    IPTR[i]=57;
		else
		{
		    if(IPTR[i]==49 && i==last_index && IPTR[i+1]==57)
		    {
			status--;
			return(*this);
		    }
		    IPTR[i]=IPTR[i]-1;
		    return(*this);
		}
	    }
	}
	else
	{
	    int i,last_index=SIZE-2-status;
	    for(i=SIZE-2;i>=last_index;i--)
	    {
		if(IPTR[i]==57)
		    IPTR[i]=48;
		else
		{
		    IPTR[i]=IPTR[i]+1;
		    return(*this);
		}
	    }
	    if(i>=0)
	    {
		IPTR[i]=49;
		status++;
		return(*this);
	    }
	    else
	    {
		status=0;
		sign=43;
		return(*this);
	    }
      }
    }
    return(*this);
}

INTEGER INTEGER::operator--(int)
{
      INTEGER temp(*this);
      --*this;
      return(temp);
}

INTEGER INTEGER::operator++(int)
{
      INTEGER temp(*this);
      ++*this;
      return(temp);
}

INTEGER INTEGER::operator+(const char*source)
{
     INTEGER temp(getLength(source)+1);
     temp=source;
     if(temp.isEmpty() || this->isEmpty())
      {
          INTEGER temp(1);
          return(temp);
      }
     else
        return(*this+temp);
}

INTEGER INTEGER::operator-(const char*source)
{
     INTEGER temp(getLength(source)+1);
     temp=source;
     if(temp.isEmpty() || this->isEmpty())
      {
          INTEGER temp(1);
          return(temp);
      }
     else
        return(*this-temp);
}

INTEGER INTEGER::operator*(const char*source)
{
     INTEGER temp(getLength(source)+1);
     temp=source;
     if(temp.isEmpty() || this->isEmpty())
      {
	  INTEGER temp(1);
          return(temp);
      }
     else
        return(*this*temp);
}

INTEGER INTEGER::operator/(const char*source)
{
     INTEGER temp(getLength(source)+1);
     temp=source;
     if(temp.isEmpty() || this->isEmpty())
      {
	  INTEGER temp(1);
          return(temp);
      }
     else
        return(*this/temp);
}

INTEGER INTEGER::operator%(const char*source)
{
     INTEGER temp(getLength(source)+1);
     temp=source;
     if(temp.isEmpty() || this->isEmpty())
     {
          INTEGER temp(1);
          return(temp);
     }
     else
	return(*this%temp);
}

INTEGER& INTEGER::operator=(const INTEGER &i2)
{
      if(i2.status!=-1)
      {
          int i,op1,op2;
          if(SIZE-2<=i2.status)  // This Condition Specified if Second Operand's status is Bigger Then Operand One status is Size-2 //
            status=SIZE-2;
	  else
            status=i2.status;
            op1=SIZE-2-status;
            op2=i2.SIZE-2-i2.status;
          for(i=0;i<=status;i++)
	  {
              IPTR[op1]=i2.IPTR[op2];
              op1++;
              op2++;
          }
	  sign=i2.sign;
          return(*this);
      }
      return(*this);
}

bool INTEGER::operator<(INTEGER&i2)
{
    if(i2.isEmpty()||this->isEmpty())
        return(false);
    else
    {
        if(sign==43 && i2.sign==45)
            return(false);
        else if(sign==43 && i2.sign==43)
	{
            if(status<i2.status)
                return(true);
            else if(status>i2.status)
                return(false);
	    else
            {
                int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
		for(round=0;round<=last_index;round++)
                {
                    if(IPTR[i]<i2.IPTR[k])
                        return(true);
                    else if(IPTR[i]>i2.IPTR[k])
                        return(false);
                        i++;
			k++;
                }
              return(false);
            }

	}
        else if(sign==45 && i2.sign==45)
        {
            if(status<i2.status)
                return(false);
	    else if(status>i2.status)
                return(true);
            else
	    {
              int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
              for(round=0;round<=last_index;round++)
              {
                    if(IPTR[i]>i2.IPTR[k])
                        return(true);
                    else if(IPTR[i]<i2.IPTR[k])
			return(false);
                        i++;
                        k++;
              }
              return(false);
	    }
        }
        return(true);
    }
}

bool INTEGER::operator<=(INTEGER &i2)
{
      if(i2.isEmpty()||this->isEmpty())
          return(false);
      else
      {
        if(sign==43 && i2.sign==45)
            return(false);
        else if(sign==43 && i2.sign==43)
	{
          if(status<i2.status)
            return(true);
          else if(status>i2.status)
            return(false);
	  else
          {
              int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
              bool result;
              for(round=0;round<=last_index;round++)
	      {
                    if(IPTR[i]<i2.IPTR[k])
                        return(true);
		    else if(IPTR[i]==i2.IPTR[k])
                        result=true;
                    else
                        return(false);
                        i++;
                        k++;
              }
	      return(result);
          }
        }
        else if(sign==45 && i2.sign==45)
        {
	  if(status<i2.status)
            return(false);
          else if(status>i2.status)
            return(true);
          else
	  {
              int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
              bool result;
	      for(round=0;round<=last_index;round++)
                {
                     if(IPTR[i]>i2.IPTR[k])
                        return(true);
                     else if(IPTR[i]==i2.IPTR[k])
                            result=true;
                     else
			return(false);
                        i++;
                        k++;
                }
            return(result);
	  }
        }
        return(true);
      }
}

bool INTEGER::operator>(INTEGER&i2)
{
      if(i2.isEmpty()||this->isEmpty())
          return(false);
      else
      {
          if(sign==43 && i2.sign==45)
            return(true);
        else if(sign==43 && i2.sign==43)
	{
            if(status>i2.status)
                return(true);
            else if(status<i2.status)
                return(false);
	    else
            {
                    int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
                    for(round=0;round<=last_index;round++)
                    {
			if(IPTR[i]>i2.IPTR[k])
                            return(true);
                        else if(IPTR[i]<i2.IPTR[k])
			    return(false);
                            i++;
                            k++;
                    }
                    return(false);
            }
        }
	else if(sign==45 && i2.sign==45)
        {
            if(status>i2.status)
                return(false);
            else if(status<i2.status)
		return(true);
            else
            {
                    int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
                    for(round=0;round<=last_index;round++)
		    {
                        if(IPTR[i]<i2.IPTR[k])
                            return(true);
			else if(IPTR[i]>i2.IPTR[k])
                            return(false);
                            i++;
                            k++;
                    }
            return(false);
            }
	}
        return(false);
      }
}

bool INTEGER::operator>=(INTEGER &i2)
{
    if(i2.isEmpty()||this->isEmpty())
          return(false);
    else
    {
        if(sign==43 && i2.sign==45)
            return(true);
	else if(sign==43 && i2.sign==43)
        {
                if(status>i2.status)
                    return(true);
                else if(status<i2.status)
                    return(false);
                else
		{
                    int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
                    bool result;
                    for(round=0;round<=last_index;round++)
                    {
			    if(IPTR[i]>i2.IPTR[k])
                                return(true);
                            else if(IPTR[i]==i2.IPTR[k])
                                result=true;
                            else
				return(false);
                                i++;
                                k++;
		    }
                    return(result);
                }
        }
        else if(sign==45 && i2.sign==45)
        {
                if(status>i2.status)
		    return(false);
                else if(status<i2.status)
                    return(true);
                else
                {
			int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
                        bool result;
                        for(round=0;round<=last_index;round++)
                        {
                                if(IPTR[i]<i2.IPTR[k])
				    return(true);
                                else if(IPTR[i]==i2.IPTR[k])
                                    result=true;
				else
                                    return(false);
                                    i++;
                                    k++;
                        }
                        return(result);
                }

        }
        return(false);
    }
}

bool INTEGER::operator==(INTEGER &i2)
{
    if(i2.isEmpty()||this->isEmpty())
        return(false);
    else
    {
        if(sign!=i2.sign)
	    return(false);
        else if(status!=i2.status)
            return(false);
        else
        {
            int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
            for(round=0;round<=last_index;round++)
	    {
                if(IPTR[i]!=i2.IPTR[k])
                    return(false);
                    i++;
                    k++;
	    }
        }
        return(true);
    }
}

bool INTEGER::operator!=(INTEGER &i2)
{
    if(i2.isEmpty()||this->isEmpty())
          return(false);
    else
    {
        if(sign!=i2.sign)
            return(true);
        else if(status!=i2.status)
	    return(true);
        else
        {
            int i=SIZE-2-status,k=i2.SIZE-2-i2.status,last_index=(status<i2.status?status:i2.status),round;
            for(round=0;round<=last_index;round++)
	    {
                if(IPTR[i]!=i2.IPTR[k])
                    return(true);
                    i++;
                    k++;
	    }
        }
        return(false);
    }
}

bool INTEGER::operator<(const char*source)
{
    INTEGER temp(getLength(source)+1);
    temp=source;
    if(temp.isEmpty() || this->isEmpty())
        return(false);
    else
        return(*this<temp);
}

bool INTEGER::operator<=(const char*source)
{
    INTEGER temp(getLength(source)+1);
    temp=source;
    if(temp.isEmpty() || this->isEmpty())
        return(false);
    else
	return(*this<=temp);
}

bool INTEGER::operator>(const char*source)
{
    INTEGER temp(getLength(source)+1);
    temp=source;
    if(temp.isEmpty() || this->isEmpty())
        return(false);
    else
        return(*this>temp);
}

bool INTEGER::operator>=(const char*source)
{
    INTEGER temp(getLength(source)+1);
    temp=source;
    if(temp.isEmpty() || this->isEmpty())
        return(false);
    else
	return(*this>=temp);
}

bool INTEGER::operator==(const char*source)
{
    INTEGER temp(getLength(source)+1);
    temp=source;
    if(temp.isEmpty() || this->isEmpty())
    {
        cout<<"Empty";
        return(false);
    }
    else
        return(*this==temp);
}

bool INTEGER::operator!=(const char*source)
{
    INTEGER temp(getLength(source)+1);
    temp=source;
    if(temp.isEmpty() || this->isEmpty())
        return(false);
    else
        return(*this!=temp);
}

int INTEGER::getLengthFormat(const char*source)
{
    int len,counts=-1,limit=49;
    bool iszero=false;
    for(len=0;source[len];len++)
    {
	if(source[len]>=limit && source[len]<=57)
        {
            counts++;
            limit=48;
        }
	else if(source[len]==48)
            iszero=true;
    }
    if(iszero)
        counts++;
    return(counts);
}

int INTEGER::getLength(const char*source)
{
    int len;
    for(len=0;source[len];len++);
    len--;
    return(len);
}

void INTEGER::getDetail(void)
{
    int i,last_index=SIZE-1,remain=SIZE-2-status;
    cout<<"\nAddress is               : = "<<this;
    if(isPositive())
        cout<<"\nNumber is '+' Positive   : ";
    else
	cout<<"\nNumber is '-' Negative   : ";
    cout<<"\nUser Size is             : = "<<SIZE-1;
    cout<<"\nActual Size in Memory is : = "<<SIZE;
    cout<<"\nStarting To End Size is  : = 0 - "<<SIZE-2<<" + ( NULL ) ";
    for(i=0;i<remain;i++)
        cout<<"-"<<" ";
    for(i=SIZE-2-status;i<last_index;i++)
    {
            cout<<IPTR[i]<<" ";
    }
    cout<<"NULL ";
    cout<<"\nUser Status is           : = "<<status+1;
    cout<<"\nActual Status is         : = "<<status;
    cout<<"\nRemaining Element Are    : = "<<(SIZE-1)-(status+1);
    cout<<"\nIPTR is                  : = ";
    cout<<sign;
    for(i=remain;i<last_index;i++)
    {
            cout<<IPTR[i];
    }
    cout<<"\n\n";
}

bool INTEGER::operator=(const char*source)
{
    int len,i,lower,limit=49,counts=-1,temp=status;
    char symbol=43;
    bool iszero=false;
    for(len=0;source[len];len++)
    {
         if(source[len]=='+' || source[len]=='-')
         {
	    symbol=source[len];
            break;
         }
    }
    for(len=0;source[len];len++)
    {
        if(source[len]>=limit && source[len]<=57)
        {
	    counts++;
            limit=48;
        }
        else if(source[len]==48)
            iszero=true;
    }
    len--;
    if(counts==-1 && iszero==true && symbol==43)
    {
        sign=43;
        IPTR[SIZE-2]=48;
        status=0;
	return(true);
    }
    if(counts>=0)
    {
        int op1,source_index;
	if(SIZE-2<=counts)
            status=SIZE-2;
        else
	    status=counts;
        op1=SIZE-2-status;
        if(symbol==43)
        {
            for(i=0;i<=len;i++)
            {
                if(source[i]>=48 && source[i]<=57)
		{
                      IPTR[op1]=source[i];
                      op1++;
                }
            }
	    return(true);
        }
        else if(symbol==45)
        {
            limit=49;
	    for(i=0;i<=len;i++)
            {
                if(source[i]>=limit && source[i]<=57)
		{
                    IPTR[op1]=source[i];
                    op1++;
                    limit=48;
                }
            }
            if(limit==48)
	    {
                sign=45;
                return(true);
            }
            else
	    {
		status=temp;
		return(false);
	    }
	}
    }
    else
	return(false);
    return(false);
}

void INTEGER::printFormat(char symbol=',',int skeep=3)
{
    if(!isEmpty())
    {
	if(skeep<=this->status+1 && skeep>0)
	{
	    int elements=this->status+1,round,limit,pair_elements,start_index=SIZE-2-status,counter=1;
	    pair_elements=elements/skeep;
	    limit=elements-pair_elements*skeep;
	    if(sign==45)
		cout<<sign;
	    for(round=1;round<=limit;round++)
	    {
		cout<<IPTR[start_index++];
	    }
	    if(limit!=0)
		cout<<symbol;
	    while(round<=elements)
	    {
		if(counter<=skeep)
		{
		    cout<<IPTR[start_index++];
		    counter++;
		}
		else
		{
		    cout<<symbol<<IPTR[start_index++];
		    counter=2;
		}
		round++;
	    }
	}
	else
	{
	    int i;
	    if(sign==45)
		cout<<sign;
	    for(i=SIZE-2-status;i<=SIZE-2;i++)
		cout<<IPTR[i];
	}
    }
    else
	cout<<"Empty";
}
//********************************* End ************************************//
