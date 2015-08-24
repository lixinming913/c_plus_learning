/*单例模式*/

class Singleton{
private:
    static Singleton* instance;
    /*构造函数私有化*/
    Singleton()
    {    }
    /*把复制构造函数和=操作符也设为私有化，防止被复制*/
    Singleton(const Singleton &)
    {    }
    
    Singleton &operator = (const Singleton &)
    {    }
    
    class destroy_single{
    public:
        ~destroy_single()
        {
            if(Singleton::instance)
                delete Singleton::instance;
        }
    };
    
    static  destroy_single des; // 静态成员，程序结束时自动调用其析构函数；
public:
    static Singleton *GetInstance()
    {
        
    }
}

Singleton* Singleton::instance = NULL;
Singleton::Singleton *GetInstance()
{
    if(instance == NULL)
    {
        lock();
        if(instance == NULL) {
            instance = new Singleton();
        }
        unlock(); 
    }
    
    return instance;
}