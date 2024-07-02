//#include <iostream>
//#include <string>
//#include <memory>
//
//// 抽象产品：车辆
//class Vehicle {
//public:
//    virtual void drive() const = 0;
//    virtual ~Vehicle() {}
//};
//
//// 具体产品：汽车
//class Car : public Vehicle {
//public:
//    void drive() const override {
//        std::cout << "Car is driving." << std::endl;
//    }
//};
//
//// 具体产品：摩托车
//class Motorcycle : public Vehicle {
//public:
//    void drive() const override {
//        std::cout << "Motorcycle is driving." << std::endl;
//    }
//};
//
//// 工厂类：车辆工厂
//class VehicleFactory {
//public:
//    // 静态方法，根据传入的类型字符串来创建相应的车辆对象
//    static Vehicle* createVehicle(const std::string& type) {
//        if (type == "Car") {
//            return new Car();
//        }
//        else if (type == "Motorcycle") {
//            return new Motorcycle();
//        }
//        // 如果传入的类型不匹配，则返回 nullptr
//        return nullptr;
//    }
//};
//
//int main() {
//    // 客户端代码
//    // 声明一个指向 Vehicle 的指针，用于接收工厂创建的对象
//    Vehicle* vehicle = nullptr;
//
//    // 尝试创建汽车
//    std::cout << "Creating Car..." << std::endl;
//    vehicle = VehicleFactory::createVehicle("Car");
//    if (vehicle) {
//        vehicle->drive();  // 调用汽车的 drive 方法
//    }
//    else {
//        std::cout << "Failed to create Car." << std::endl;
//    }
//
//    // 尝试创建摩托车
//    std::cout << "\nCreating Motorcycle..." << std::endl;
//    vehicle = VehicleFactory::createVehicle("Motorcycle");
//    if (vehicle) {
//        vehicle->drive();  // 调用摩托车的 drive 方法
//    }
//    else {
//        std::cout << "Failed to create Motorcycle." << std::endl;
//    }
//
//    // 释放之前创建的车辆对象
//    delete vehicle;
//
//    return 0;
//}




//工厂方法模式

//#include <iostream>
//#include <memory>
//
//// 抽象产品：车辆
//class Vehicle {
//public:
//    virtual void drive() const = 0;
//    virtual ~Vehicle() {}
//};
//
//// 具体产品：汽车
//class Car : public Vehicle {
//public:
//    void drive() const override {
//        std::cout << "Car is driving on the highway." << std::endl;
//    }
//};
//
//// 具体产品：摩托车
//class Motorcycle : public Vehicle {
//public:
//    void drive() const override {
//        std::cout << "Motorcycle is driving on the street." << std::endl;
//    }
//};
//
//// 抽象工厂：车辆工厂
//class VehicleFactory {
//public:
//    virtual std::unique_ptr<Vehicle> createVehicle() const = 0;
//    virtual ~VehicleFactory() {}
//};
//
//// 具体工厂：汽车工厂
//class CarFactory : public VehicleFactory {
//public:
//    std::unique_ptr<Vehicle> createVehicle() const override {
//        return std::make_unique<Car>();
//    }
//};
//
//// 具体工厂：摩托车工厂
//class MotorcycleFactory : public VehicleFactory {
//public:
//    std::unique_ptr<Vehicle> createVehicle() const override {
//        return std::make_unique<Motorcycle>();
//    }
//};
//
//// 客户端代码
//int main() {
//    // 使用智能指针管理资源
//    std::unique_ptr<VehicleFactory> factory;
//
//    // 需要创建汽车
//    factory = std::make_unique<CarFactory>();
//    factory->createVehicle()->drive();
//
//    // 需要创建摩托车
//    factory = std::make_unique<MotorcycleFactory>();
//    factory->createVehicle()->drive();
//
//    return 0;
//}



//#include <iostream>
//#include <memory>
//
//// 抽象产品：颜色
//class Color {
//public:
//    virtual void applyColor() const = 0;
//    virtual ~Color() {}
//};
//
//// 具体产品：红色
//class Red : public Color {
//public:
//    void applyColor() const override {
//        std::cout << "Applying Red color." << std::endl;
//    }
//};
//
//// 具体产品：蓝色
//class Blue : public Color {
//public:
//    void applyColor() const override {
//        std::cout << "Applying Blue color." << std::endl;
//    }
//};
//
//// 抽象产品：形状
//class Shape {
//public:
//    virtual void applyShape() const = 0;
//    virtual ~Shape() {}
//};
//
//// 具体产品：圆形
//class Circle : public Shape {
//public:
//    void applyShape() const override {
//        std::cout << "Applying Circle shape." << std::endl;
//    }
//};
//
//// 具体产品：正方形
//class Square : public Shape {
//public:
//    void applyShape() const override {
//        std::cout << "Applying Square shape." << std::endl;
//    }
//};
//
//// 抽象工厂：艺术工厂
//class ArtFactory {
//public:
//    virtual std::unique_ptr<Color> createColor() const = 0;
//    virtual std::unique_ptr<Shape> createShape() const = 0;
//    virtual ~ArtFactory() {}
//};
//
//// 具体工厂：现代艺术工厂
//class ModernArtFactory : public ArtFactory {
//public:
//    std::unique_ptr<Color> createColor() const override {
//        return std::make_unique<Red>();
//    }
//    std::unique_ptr<Shape> createShape() const override {
//        return std::make_unique<Circle>();
//    }
//};
//
//// 具体工厂：印象艺术工厂
//class ImpressionistArtFactory : public ArtFactory {
//public:
//    std::unique_ptr<Color> createColor() const override {
//        return std::make_unique<Blue>();
//    }
//    std::unique_ptr<Shape> createShape() const override {
//        return std::make_unique<Square>();
//    }
//};
//
//// 客户端代码
//int main() {
//    std::unique_ptr<ArtFactory> factory;
//
//    // 使用现代艺术工厂
//    factory = std::make_unique<ModernArtFactory>();
//    auto color = factory->createColor();
//    auto shape = factory->createShape();
//    color->applyColor();
//    shape->applyShape();
//
//    // 使用印象艺术工厂
//    factory = std::make_unique<ImpressionistArtFactory>();
//    color = factory->createColor();
//    shape = factory->createShape();
//    color->applyColor();
//    shape->applyShape();
//
//    return 0;
//}



//#include <iostream>
//#include <memory>
//
//class Singleton {
//private:
//    // 私有构造函数，防止外部通过new创建实例
//    Singleton() {}
//
//public:
//    // 禁止复制构造函数
//    Singleton(const Singleton&) = delete;
//    // 禁止赋值操作
//    Singleton& operator=(const Singleton&) = delete;
//
//    // 提供一个静态公有方法，用于获取类的唯一实例
//    static Singleton& getInstance() {
//        static Singleton instance; // 局部静态变量，确保线程安全并懒加载
//        return instance;
//    }
//
//    void doSomething() const {
//        std::cout << "Doing something important." << std::endl;
//    }
//};
//
//int main() {
//    // 获取单例对象的引用，并调用方法
//    Singleton& singleton = Singleton::getInstance();
//    singleton.doSomething();
//
//    // 再次获取单例对象的引用，这将返回同一个实例
//    Singleton& anotherSingleton = Singleton::getInstance();
//    anotherSingleton.doSomething();
//
//    // 打印地址，证明两次获取的是同一个实例
//    std::cout << "Singleton instance address: " << &singleton << std::endl;
//    std::cout << "Another singleton instance address: " << &anotherSingleton << std::endl;
//
//    return 0;
//}



//#include <iostream>
//#include <string>
//
//// 产品角色：汽车
//class Car {
//private:
//    std::string engine;
//    std::string tires;
//    std::string bodyColor;
//
//public:
//    // 构造函数私有化，确保只能通过生成器来创建
//    Car(const std::string& engine, const std::string& tires, const std::string& bodyColor)
//        : engine(engine), tires(tires), bodyColor(bodyColor) {}
//
//    void showSpecs() const {
//        std::cout << "Car Specifications:" << std::endl;
//        std::cout << "Engine: " << engine << std::endl;
//        std::cout << "Tires: " << tires << std::endl;
//        std::cout << "Body Color: " << bodyColor << std::endl;
//    }
//};
//
//// 生成器接口
//class CarBuilder {
//public:
//    virtual ~CarBuilder() {}
//    virtual CarBuilder* setEngine(const std::string& engine) = 0;
//    virtual CarBuilder* setTires(const std::string& tires) = 0;
//    virtual CarBuilder* setBodyColor(const std::string& color) = 0;
//    virtual Car* getCar() = 0;
//};
//
//// 具体生成器
//class ConcreteCarBuilder : public CarBuilder {
//private:
//    Car* car;
//    std::string engine;
//    std::string tires;
//    std::string bodyColor;
//
//public:
//    ConcreteCarBuilder() : car(nullptr) {}
//
//    CarBuilder* setEngine(const std::string& engine) override {
//        this->engine = engine;
//        return this;
//    }
//
//    CarBuilder* setTires(const std::string& tires) override {
//        this->tires = tires;
//        return this;
//    }
//
//    CarBuilder* setBodyColor(const std::string& color) override {
//        this->bodyColor = color;
//        return this;
//    }
//
//    Car* getCar() override {
//        if (car == nullptr) {
//            car = new Car(engine, tires, bodyColor);
//        }
//        return car;
//    }
//};
//
//// 指挥者
//class CarDirector {
//public:
//    Car* constructCar(CarBuilder* builder) {
//        return builder->setEngine("V8")
//            ->setTires("Michelin")
//            ->setBodyColor("Red")
//            ->getCar();
//    }
//};
//
//// 客户端代码
//int main() {
//    CarBuilder* builder = new ConcreteCarBuilder();
//    CarDirector director;
//    Car* car = director.constructCar(builder);
//    car->showSpecs(); // 打印汽车规格
//
//    delete car; // 清理资源
//    delete builder;
//    return 0;
//}





//#include <iostream>
//#include <memory>
//
//// 原型接口
//class Animal {
//public:
//    virtual ~Animal() {}
//
//    // 克隆方法
//    virtual std::unique_ptr<Animal> clone() const = 0;
//
//    // 显示动物信息
//    virtual void showInfo() const = 0;
//};
//
//// 具体原型：羊
//class Sheep : public Animal {
//private:
//    std::string name;
//
//public:
//    Sheep(const std::string& name) : name(name) {}
//
//    // 克隆羊
//    std::unique_ptr<Animal> clone() const override {
//        return std::make_unique<Sheep>(name);
//    }
//
//    // 显示羊的信息
//    void showInfo() const override {
//        std::cout << "Sheep: " << name << std::endl;
//    }
//};
//
//// 客户端代码
//int main() {
//    // 创建一个羊的实例
//    std::unique_ptr<Animal> original = std::make_unique<Sheep>("Little Sheep");
//
//    // 克隆羊
//    std::unique_ptr<Animal> cloned = original->clone();
//
//    // 打印原始羊的信息
//    original->showInfo();
//
//    // 打印克隆羊的信息
//    cloned->showInfo();
//
//    return 0;
//}



////类对象适配器
//#include <iostream>
//
//// 定义一个目标接口
//class Target {
//public:
//    virtual void request() = 0;
//    virtual ~Target() {}
//};
//
//// 定义一个期望的适配者类
//class Adaptee {
//public:
//    void specificRequest() {
//        std::cout << "Executing specific request in Adaptee" << std::endl;
//    }
//};
//
//// 类适配器模式
//class Adapter : public Target {
//private:
//    Adaptee adaptee;
//public:
//    void request() override {
//        // 调用适配者的方法
//        adaptee.specificRequest();
//    }
//};
//
//int main() {
//    // 创建适配者对象
//    Adaptee adapteeObj;
//
//    // 创建适配器对象，并将其作为目标接口的对象使用
//    Target* adapter = new Adapter();
//
//    // 使用适配器来执行请求
//    std::cout << "Client: I can use the target via adapter: " << std::endl;
//    adapter->request();
//
//    delete adapter; // 清理分配的内存
//    return 0;
//}




//#include <iostream>
//
//// 定义一个目标接口
//class Target {
//public:
//    virtual void request() = 0;
//    virtual ~Target() {}
//};
//
//// 定义一个期望的适配者类
//class Adaptee {
//public:
//    void specificRequest() {
//        std::cout << "Adaptee: Executing specific request" << std::endl;
//    }
//};
//
//// 对象适配器
//class Adapter : public Target {
//private:
//    Adaptee adaptee; // 包含一个Adaptee对象
//
//public:
//    // 实现Target接口的request方法
//    void request() override {
//        // 将Adaptee的specificRequest方法适配为Target接口的request方法
//        adaptee.specificRequest();
//    }
//};
//
//int main() {
//    // 创建Adaptee对象
//    Adaptee adapteeObj;
//
//    // 创建Adapter对象，它内部包含一个Adaptee对象
//    Adapter adapterObj;
//
//    // 通过Adapter对象调用request方法
//    std::cout << "Client: I can use the target via adapter: " << std::endl;
//    adapterObj.request();
//
//    return 0;
//}




//#include <iostream>
//
//// 目标接口
//class Target {
//public:
//    virtual void request() = 0;
//    virtual ~Target() {}
//};
//
//// 适配者接口
//class Adaptee {
//public:
//    void specificRequest() {
//        std::cout << "Adaptee: Doing something specific" << std::endl;
//    }
//};
//
//// 接口适配器
//class Adapter : public Target {
//private:
//    Adaptee adaptee;
//
//public:
//    Adapter(Adaptee& adaptee_) : adaptee(adaptee_) {}
//
//    void request() override {
//        // 将Adaptee的specificRequest方法适配为Target接口的request方法
//        adaptee.specificRequest();
//    }
//};
//
//int main() {
//    // 创建Adaptee对象
//    Adaptee adapteeObj;
//
//    // 创建Adapter对象，它将Adaptee对象作为参数
//    Adapter adapter(adapteeObj);
//
//    // 通过Adapter对象调用request方法
//    std::cout << "Client: I can use the target via adapter: " << std::endl;
//    adapter.request();
//
//    return 0;
//}


//
//#include <iostream>
//
//// 抽象组件
//class Component {
//public:
//    virtual void operation() = 0; // 定义一个接口方法
//    virtual ~Component() {} // 虚析构函数确保派生类的析构函数被调用
//};
//
//// 具体组件
//class ConcreteComponent : public Component {
//public:
//    void operation() override {
//        std::cout << "ConcreteComponent: 基本操作" << std::endl;
//    }
//};
//
//// 抽象装饰者类
//class Decorator : public Component {
//protected:
//    Component* wrappedComponent; // 持有组件的指针
//
//public:
//    Decorator(Component* component) : wrappedComponent(component) {}
//
//    // 必须重写operation方法
//    void operation() override {
//        if (wrappedComponent != nullptr) {
//            wrappedComponent->operation();
//        }
//    }
//
//    // 虚析构函数
//    virtual ~Decorator() {}
//};
//
//// 具体装饰者A
//class ConcreteDecoratorA : public Decorator {
//public:
//    ConcreteDecoratorA(Component* component) : Decorator(component) {}
//
//    void operation() override {
//        if (wrappedComponent != nullptr) {
//            wrappedComponent->operation(); // 调用被装饰者的方法
//            addedBehaviorA(); // 添加新的行为
//        }
//    }
//
//    void addedBehaviorA() {
//        std::cout << "ConcreteDecoratorA: 添加的行为A" << std::endl;
//    }
//};
//
//// 具体装饰者B
//class ConcreteDecoratorB : public Decorator {
//public:
//    ConcreteDecoratorB(Component* component) : Decorator(component) {}
//
//    void operation() override {
//        if (wrappedComponent != nullptr) {
//            wrappedComponent->operation(); // 调用被装饰者的方法
//            addedBehaviorB(); // 添加新的行为
//        }
//    }
//
//    void addedBehaviorB() {
//        std::cout << "ConcreteDecoratorB: 添加的行为B" << std::endl;
//    }
//};
//
//int main() {
//    // 创建具体组件
//    ConcreteComponent* c = new ConcreteComponent();
//
//    // 创建装饰者A和B，并装饰具体组件
//    ConcreteDecoratorA* decoratorA = new ConcreteDecoratorA(c);
//    ConcreteDecoratorB* decoratorB = new ConcreteDecoratorB(decoratorA);
//
//    // 执行操作，将看到装饰者添加的行为
//    std::cout << "装饰前:" << std::endl;
//    c->operation();
//
//    std::cout << "\n使用DecoratorA装饰后:" << std::endl;
//    decoratorA->operation();
//
//    std::cout << "\n使用DecoratorB进一步装饰后:" << std::endl;
//    decoratorB->operation();
//
//    // 清理资源
//    delete decoratorB;
//    delete decoratorA;
//    delete c;
//
//    return 0;
//}





//#include <iostream>
//
//// 定义一个接口，这样代理类和委托类都可以实现它
//class ImageLoader {
//public:
//    virtual void load() = 0;
//    virtual ~ImageLoader() {}
//};
//
//// 委托类，实际执行加载操作的类
//class RealImageLoader : public ImageLoader {
//public:
//    void load() override {
//        std::cout << "RealImageLoader: Loading image..." << std::endl;
//        // 执行加载图片的代码
//    }
//};
//
//// 代理类，增加了额外的功能
//class ImageLoaderProxy : public ImageLoader {
//private:
//    ImageLoader* realLoader; // 指向委托类的指针
//
//public:
//    ImageLoaderProxy(ImageLoader* loader) : realLoader(loader) {}
//
//    void load() override {
//        // 代理类可以在这里添加额外的功能
//        std::cout << "ImageLoaderProxy: Pre-loading setup..." << std::endl;
//
//        // 调用委托类的方法
//        realLoader->load();
//
//        // 可以在这里添加加载后的额外功能
//        std::cout << "ImageLoaderProxy: Post-loading cleanup..." << std::endl;
//    }
//};
//
//int main() {
//    // 创建委托对象
//    RealImageLoader* realLoader = new RealImageLoader();
//
//    // 创建代理对象，将委托对象传递给代理
//    ImageLoaderProxy* proxy = new ImageLoaderProxy(realLoader);
//
//    // 通过代理对象调用load方法
//    std::cout << "Using proxy to load image:" << std::endl;
//    proxy->load();
//
//    // 清理资源
//    delete proxy;
//    delete realLoader;
//
//    return 0;
//}



//#include <iostream>
//
//// 定义一个接口，这样代理类和委托类都可以实现它
//class ImageLoader {
//public:
//    virtual void load() = 0;
//    virtual ~ImageLoader() {}
//};
//
//// 委托类，实际执行加载操作的类
//class RealImageLoader : public ImageLoader {
//public:
//    void load() override {
//        std::cout << "RealImageLoader: Loading image..." << std::endl;
//        // 执行加载图片的代码
//    }
//};
//
//// 代理类，增加了额外的功能
//class ImageLoaderProxy : public ImageLoader {
//private:
//    ImageLoader* realLoader; // 指向委托类的指针
//
//public:
//    ImageLoaderProxy(ImageLoader* loader) : realLoader(loader) {}
//
//    void load() override {
//        // 代理类可以在这里添加额外的功能
//        std::cout << "ImageLoaderProxy: Pre-loading setup..." << std::endl;
//
//        // 调用委托类的方法
//        realLoader->load();
//
//        // 可以在这里添加加载后的额外功能
//        std::cout << "ImageLoaderProxy: Post-loading cleanup..." << std::endl;
//    }
//};
//
//int main() {
//    // 创建委托对象
//    RealImageLoader* realLoader = new RealImageLoader();
//
//    // 创建代理对象，将委托对象传递给代理
//    ImageLoaderProxy* proxy = new ImageLoaderProxy(realLoader);
//
//    // 通过代理对象调用load方法
//    std::cout << "Using proxy to load image:" << std::endl;
//    proxy->load();
//
//    // 清理资源
//    delete proxy;
//    delete realLoader;
//
//    return 0;
//}



////动态代理
//#include <iostream>
//#include <memory>
//
//// 定义一个接口，这样代理类和委托类都可以实现它
//class ImageLoader {
//public:
//    virtual void load() = 0;
//    virtual ~ImageLoader() {}
//};
//
//// 委托类，实际执行加载操作的类
//class RealImageLoader : public ImageLoader {
//public:
//    void load() override {
//        std::cout << "RealImageLoader: Loading image..." << std::endl;
//        // 执行加载图片的代码
//    }
//};
//
//// 代理类，增加了额外的功能
//class ImageLoaderProxy : public ImageLoader {
//private:
//    std::unique_ptr<ImageLoader> realLoader; // 指向委托类的智能指针
//
//public:
//    ImageLoaderProxy(std::unique_ptr<ImageLoader> loader) : realLoader(std::move(loader)) {}
//
//    void load() override {
//        // 代理类可以在这里添加额外的功能
//        std::cout << "ImageLoaderProxy: Pre-loading setup..." << std::endl;
//
//        // 调用委托类的方法
//        realLoader->load();
//
//        // 可以在这里添加加载后的额外功能
//        std::cout << "ImageLoaderProxy: Post-loading cleanup..." << std::endl;
//    }
//};
//
//// 动态创建代理的工厂函数
//std::unique_ptr<ImageLoader> createDynamicProxy(std::unique_ptr<ImageLoader>&& realLoader) {
//    return std::make_unique<ImageLoaderProxy>(std::move(realLoader));
//}
//
//int main() {
//    // 创建委托对象
//    auto realLoader = std::make_unique<RealImageLoader>();
//
//    // 动态创建代理对象
//    auto proxy = createDynamicProxy(std::move(realLoader));
//
//    // 通过代理对象调用load方法
//    std::cout << "Using proxy to load image:" << std::endl;
//    proxy->load();
//
//    return 0;
//}




//#include <iostream>
//#include <functional>
//#include <map>
//
//// 定义一个接口，这样代理类和委托类都可以实现它
//class ISubject {
//public:
//    virtual void request() = 0;
//    virtual ~ISubject() {}
//};
//
//// 委托类，实际执行请求操作的类
//class RealSubject : public ISubject {
//public:
//    void request() override {
//        std::cout << "RealSubject: Handling request..." << std::endl;
//    }
//};
//
//// 代理类模板，可以代理任何实现了ISubject接口的类
//template <typename T>
//class SubjectProxy : public ISubject {
//private:
//    T* realSubject; // 指向委托类的指针
//
//public:
//    SubjectProxy(T* subject) : realSubject(subject) {}
//
//    void request() override {
//        // 代理类可以在这里添加额外的功能
//        std::cout << "SubjectProxy: Before request" << std::endl;
//
//        // 调用委托类的方法
//        realSubject->request();
//
//        // 可以在这里添加请求后的额外功能
//        std::cout << "SubjectProxy: After request" << std::endl;
//    }
//};
//
//int main() {
//    // 创建委托对象
//    RealSubject* realSubject = new RealSubject();
//
//    // 创建代理对象，代理RealSubject
//    ISubject* proxy = new SubjectProxy<RealSubject>(realSubject);
//
//    // 通过代理对象调用request方法
//    std::cout << "Using proxy:" << std::endl;
//    proxy->request();
//
//    // 清理资源
//    delete proxy;
//    delete realSubject;
//
//    return 0;
//}



//外观模式
//#include <iostream>
//
//// 子系统类A
//class SubSystemA {
//public:
//    void operationA() {
//        std::cout << "SubSystemA: Operation A" << std::endl;
//    }
//};
//
//// 子系统类B
//class SubSystemB {
//public:
//    void operationB() {
//        std::cout << "SubSystemB: Operation B" << std::endl;
//    }
//};
//
//// 子系统类C
//class SubSystemC {
//public:
//    void operationC() {
//        std::cout << "SubSystemC: Operation C" << std::endl;
//    }
//};
//
//// 外观类
//class Facade {
//private:
//    SubSystemA* subA;
//    SubSystemB* subB;
//    SubSystemC* subC;
//
//public:
//    Facade() : subA(new SubSystemA()), subB(new SubSystemB()), subC(new SubSystemC()) {}
//    ~Facade() {
//        delete subA;
//        delete subB;
//        delete subC;
//    }
//
//    void operation() {
//        std::cout << "Facade: Starting operation..." << std::endl;
//        subA->operationA();
//        subB->operationB();
//        subC->operationC();
//        std::cout << "Facade: Finishing operation..." << std::endl;
//    }
//};
//
//int main() {
//    Facade facade;
//    facade.operation();
//
//    return 0;
//}



////桥接模式
//#include <iostream>
//#include <string>
//
//// 抽象形状类
//class Shape {
//public:
//    virtual ~Shape() {}
//    virtual void draw() const = 0;
//};
//
//// 抽象实现类
//class ShapeImpl {
//public:
//    virtual ~ShapeImpl() {}
//    virtual void applyColor() const = 0;
//};
//
//// 具体形状类
//class Circle : public Shape {
//private:
//    ShapeImpl* shapeImpl;
//public:
//    Circle(ShapeImpl* shapeImpl) : shapeImpl(shapeImpl) {}
//    ~Circle() { delete shapeImpl; }
//    void draw() const override {
//        shapeImpl->applyColor();
//        std::cout << "Drawing a Circle" << std::endl;
//    }
//};
//
//// 具体实现类
//class RedCircle : public ShapeImpl {
//public:
//    void applyColor() const override {
//        std::cout << "Applying Red color" << std::endl;
//    }
//};
//
//class BlueCircle : public ShapeImpl {
//public:
//    void applyColor() const override {
//        std::cout << "Applying Blue color" << std::endl;
//    }
//};
//
//// 客户端代码
//int main() {
//    Shape* shape = new Circle(new RedCircle());
//    shape->draw();
//
//    delete shape; // 清理内存
//
//    shape = new Circle(new BlueCircle());
//    shape->draw();
//
//    delete shape; // 清理内存
//
//    return 0;
//}



////组合模式
//#include <iostream>
//#include <vector>
//#include <memory>
//
//// 抽象构件
//class Component {
//public:
//    virtual void operation() = 0;
//    virtual ~Component() {}
//};
//
//// 叶节点
//class Leaf : public Component {
//public:
//    void operation() override {
//        std::cout << "Leaf is performing operation" << std::endl;
//    }
//};
//
//// 组合节点
//class Composite : public Component {
//private:
//    std::vector<std::unique_ptr<Component>> children;
//
//public:
//    void add(std::unique_ptr<Component> component) {
//        children.push_back(std::move(component));
//    }
//
//    void operation() override {
//        std::cout << "Composite is performing operation" << std::endl;
//        for (auto& child : children) {
//            child->operation();
//        }
//    }
//};
//
//// 客户端代码
//int main() {
//    std::unique_ptr<Composite> root = std::make_unique<Composite>();
//
//    std::unique_ptr<Composite> part1 = std::make_unique<Composite>();
//    part1->add(std::make_unique<Leaf>());
//    part1->add(std::make_unique<Leaf>());
//
//    std::unique_ptr<Leaf> leaf1 = std::make_unique<Leaf>();
//    std::unique_ptr<Leaf> leaf2 = std::make_unique<Leaf>();
//
//    root->add(std::move(part1));
//    root->add(std::move(leaf1));
//    root->add(std::move(leaf2));
//
//    root->operation();
//
//    return 0;
//}



////享元模式
//#include <iostream>
//#include <unordered_map>
//#include <memory>
//
//// 享元接口
//class Flyweight {
//public:
//    virtual ~Flyweight() {}
//    virtual void operation(std::string extrinsicState) = 0;
//};
//
//// 具体享元类
//class ConcreteFlyweight : public Flyweight {
//private:
//    std::string intrinsicState;
//
//public:
//    ConcreteFlyweight(const std::string& intrinsicState)
//        : intrinsicState(intrinsicState) {}
//
//    void operation(std::string extrinsicState) override {
//        std::cout << "Intrinsic State: " << intrinsicState
//            << ", Extrinsic State: " << extrinsicState << std::endl;
//    }
//};
//
//// 享元工厂
//class FlyweightFactory {
//private:
//    std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;
//
//public:
//    std::shared_ptr<Flyweight> getFlyweight(const std::string& key) {
//        if (flyweights.find(key) == flyweights.end()) {
//            flyweights[key] = std::make_shared<ConcreteFlyweight>(key);
//        }
//        return flyweights[key];
//    }
//};
//
//// 客户端代码
//int main() {
//    FlyweightFactory factory;
//
//    std::shared_ptr<Flyweight> flyweight1 = factory.getFlyweight("X");
//    flyweight1->operation("State1");
//
//    std::shared_ptr<Flyweight> flyweight2 = factory.getFlyweight("X");
//    flyweight2->operation("State2");
//
//    std::shared_ptr<Flyweight> flyweight3 = factory.getFlyweight("Y");
//    flyweight3->operation("State3");
//
//    return 0;
//}


////策略模式
//#include <iostream>
//#include <string>
//
//// 策略接口
//class Strategy {
//public:
//    virtual ~Strategy() {}
//    virtual void execute() const = 0;
//};
//
//// 具体策略A
//class ConcreteStrategyA : public Strategy {
//public:
//    void execute() const override {
//        std::cout << "Executing ConcreteStrategyA" << std::endl;
//    }
//};
//
//// 具体策略B
//class ConcreteStrategyB : public Strategy {
//public:
//    void execute() const override {
//        std::cout << "Executing ConcreteStrategyB" << std::endl;
//    }
//};
//
//// 上下文
//class Context {
//private:
//    Strategy* strategy;
//
//public:
//    Context(Strategy* strategy) : strategy(strategy) {}
//    ~Context() { delete strategy; }
//
//    void setStrategy(Strategy* strategy) {
//        delete this->strategy;
//        this->strategy = strategy;
//    }
//
//    void executeStrategy() const {
//        strategy->execute();
//    }
//};
//
//// 客户端代码
//int main() {
//    // 创建上下文并初始化策略
//    Context context(new ConcreteStrategyA());
//    context.executeStrategy();  // 执行策略A
//
//    // 改变策略
//    context.setStrategy(new ConcreteStrategyB());
//    context.executeStrategy();  // 执行策略B
//
//    return 0;
//}



//模版模式
//#include <iostream>
//#include <string>
//
//// 抽象类
//class AbstractClass {
//public:
//    // 模板方法
//    void templateMethod() {
//        stepOne();
//        stepTwo();
//        stepThree();
//    }
//
//protected:
//    // 基本步骤，子类必须实现
//    virtual void stepOne() = 0;
//    virtual void stepTwo() = 0;
//    virtual void stepThree() = 0;
//};
//
//// 具体类A
//class ConcreteClassA : public AbstractClass {
//protected:
//    void stepOne() override {
//        std::cout << "ConcreteClassA: Step One" << std::endl;
//    }
//
//    void stepTwo() override {
//        std::cout << "ConcreteClassA: Step Two" << std::endl;
//    }
//
//    void stepThree() override {
//        std::cout << "ConcreteClassA: Step Three" << std::endl;
//    }
//};
//
//// 具体类B
//class ConcreteClassB : public AbstractClass {
//protected:
//    void stepOne() override {
//        std::cout << "ConcreteClassB: Step One" << std::endl;
//    }
//
//    void stepTwo() override {
//        std::cout << "ConcreteClassB: Step Two" << std::endl;
//    }
//
//    void stepThree() override {
//        std::cout << "ConcreteClassB: Step Three" << std::endl;
//    }
//};
//
//// 客户端代码
//int main() {
//    AbstractClass* a = new ConcreteClassA();
//    a->templateMethod();
//    delete a;
//
//    a = new ConcreteClassB();
//    a->templateMethod();
//    delete a;
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// 观察者接口
//class Observer {
//public:
//    virtual ~Observer() {}
//    virtual void update() = 0; // 当被通知时调用的方法
//};
//
//// 主题接口
//class Subject {
//private:
//    std::vector<Observer*> observers; // 观察者列表
//
//public:
//    virtual ~Subject() {}
//
//    void attach(Observer* observer) {
//        observers.push_back(observer); // 添加观察者
//    }
//
//    void detach(Observer* observer) {
//        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end()); // 删除观察者
//    }
//
//    void notify() {
//        for (Observer* observer : observers) {
//            observer->update(); // 通知所有观察者
//        }
//    }
//};
//
//// 具体观察者
//class ConcreteObserver : public Observer {
//private:
//    std::string name;
//
//public:
//    ConcreteObserver(const std::string& name) : name(name) {}
//
//    void update() override {
//        std::cout << "Observer " << name << " is notified." << std::endl;
//    }
//};
//
//// 具体主题
//class ConcreteSubject : public Subject {
//private:
//    std::string state;
//
//public:
//    void setState(const std::string& state) {
//        this->state = state;
//        notify(); // 如果状态改变，通知所有观察者
//    }
//
//    std::string getState() const {
//        return state;
//    }
//};
//
//// 客户端代码
//int main() {
//    ConcreteSubject subject;
//
//    ConcreteObserver observer1("1");
//    ConcreteObserver observer2("2");
//
//    subject.attach(&observer1);
//    subject.attach(&observer2);
//
//    subject.setState("New State 1"); // 通知所有观察者
//
//    subject.detach(&observer1);
//
//    subject.setState("New State 2"); // 只有observer2会被通知
//
//    return 0;
//}





//#include <iostream>
//#include <string>
//
//// 请求接口
//class Request {
//public:
//    std::string message;
//    Request(const std::string& msg) : message(msg) {}
//};
//
//// 处理器接口
//class Handler {
//public:
//    virtual ~Handler() {}
//    virtual void HandleRequest(Request* request) = 0;
//    virtual void SetNext(Handler* next) = 0;
//};
//
//// 具体处理器
//class ConcreteHandlerA : public Handler {
//    Handler* next;
//public:
//    ConcreteHandlerA() : next(nullptr) {}
//    void HandleRequest(Request* request) override {
//        if (request->message == "Request A") {
//            std::cout << "Handled by A" << std::endl;
//        }
//        else {
//            if (next != nullptr) {
//                next->HandleRequest(request);
//            }
//        }
//    }
//    void SetNext(Handler* nextHandler) override {
//        next = nextHandler;
//    }
//};
//
//class ConcreteHandlerB : public Handler {
//    Handler* next;
//public:
//    ConcreteHandlerB() : next(nullptr) {}
//    void HandleRequest(Request* request) override {
//        if (request->message == "Request B") {
//            std::cout << "Handled by B" << std::endl;
//        }
//        else {
//            if (next != nullptr) {
//                next->HandleRequest(request);
//            }
//        }
//    }
//    void SetNext(Handler* nextHandler) override {
//        next = nextHandler;
//    }
//};
//
//// 客户端代码
//int main() {
//    Handler* handlerA = new ConcreteHandlerA();
//    Handler* handlerB = new ConcreteHandlerB();
//
//    handlerA->SetNext(handlerB); // 将B设置为A的后继
//
//    Request* request1 = new Request("Request A");
//    Request* request2 = new Request("Request B");
//    Request* request3 = new Request("Request C");
//
//    handlerA->HandleRequest(request1); // 将请求传递给A，A处理
//    handlerA->HandleRequest(request2); // 将请求传递给A，A传递给B，B处理
//    handlerA->HandleRequest(request3); // 将请求传递给A，然后传递给B，B不处理
//
//    delete request1;
//    delete request2;
//    delete request3;
//    delete handlerA;
//    delete handlerB;
//
//    return 0;
//}



////命令模式
//#include <iostream>
//#include <string>
//#include <memory>
//
//// 接收者（Receiver）
//class Receiver {
//public:
//    virtual ~Receiver() {}
//    virtual void Action() = 0;
//};
//
//// 具体接收者
//class ConcreteReceiver : public Receiver {
//public:
//    void Action() override {
//        std::cout << "Action has been executed." << std::endl;
//    }
//};
//
//// 命令接口（Command）
//class Command {
//public:
//    virtual ~Command() {}
//    virtual void Execute() = 0;
//    virtual void Undo() = 0; // 添加撤销操作
//};
//
//// 具体命令
//class ConcreteCommand : public Command {
//private:
//    std::unique_ptr<Receiver> receiver;
//public:
//    ConcreteCommand(std::unique_ptr<Receiver>&& rcvr) : receiver(std::move(rcvr)) {}
//    void Execute() override {
//        receiver->Action();
//    }
//    void Undo() override {
//        std::cout << "Action has been undone." << std::endl;
//    }
//};
//
//// 调用者（Invoker）
//class Invoker {
//private:
//    std::unique_ptr<Command> command;
//public:
//    void SetCommand(std::unique_ptr<Command>&& cmd) {
//        command = std::move(cmd);
//    }
//    void ExecuteCommand() {
//        if (command) {
//            command->Execute();
//        }
//    }
//    void UndoCommand() {
//        if (command) {
//            command->Undo();
//        }
//    }
//};
//
//// 客户端代码
//int main() {
//    // 创建接收者
//    auto receiver = std::make_unique<ConcreteReceiver>();
//
//    // 创建具体命令
//    auto command = std::make_unique<ConcreteCommand>(std::move(receiver));
//
//    // 创建调用者
//    Invoker invoker;
//
//    // 设置命令
//    invoker.SetCommand(std::move(command));
//
//    // 执行命令
//    invoker.ExecuteCommand();
//
//    // 撤销命令
//    invoker.UndoCommand();
//
//    return 0;
//}




////状态模式
//#include <iostream>
//#include <memory>
//
//// 状态接口
//class State {
//public:
//    virtual ~State() {}
//    virtual void Handle() = 0;
//};
//
//// 具体状态类A
//class ConcreteStateA : public State {
//public:
//    void Handle() override {
//        std::cout << "Handling request in ConcreteStateA" << std::endl;
//    }
//};
//
//// 具体状态类B
//class ConcreteStateB : public State {
//public:
//    void Handle() override {
//        std::cout << "Handling request in ConcreteStateB" << std::endl;
//    }
//};
//
//// 上下文环境类
//class Context {
//private:
//    std::unique_ptr<State> state;
//public:
//    void SetState(std::unique_ptr<State>&& newState) {
//        state = std::move(newState);
//    }
//
//    void Request() {
//        state->Handle();
//    }
//};
//
//// 客户端代码
//int main() {
//    // 创建状态对象
//    auto stateA = std::make_unique<ConcreteStateA>();
//    auto stateB = std::make_unique<ConcreteStateB>();
//
//    // 创建上下文环境对象
//    Context context;
//
//    // 设置状态为A并处理请求
//    context.SetState(std::move(stateA));
//    context.Request();
//
//    // 更改状态为B并处理请求
//    context.SetState(std::move(stateB));
//    context.Request();
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//
//// 此处定义了两个元素类，分别是 ElementA 和 ElementB
//class ElementA;
//class ElementB;
//
//// 定义一个抽象访问者类 Visitor
//class Visitor {
//public:
//    virtual void visitElementA(ElementA* element) = 0;
//    virtual void visitElementB(ElementB* element) = 0;
//};
//
//// 具体的访问者类 ConcreteVisitor，实现了对两种元素的访问操作
//class ConcreteVisitor : public Visitor {
//public:
//    void visitElementA(ElementA* element) override {
//        std::cout << "Visited ElementA" << std::endl;
//    }
//
//    void visitElementB(ElementB* element) override {
//        std::cout << "Visited ElementB" << std::endl;
//    }
//};
//
//// 定义一个抽象元素类 Element
//class Element {
//public:
//    virtual void accept(Visitor* visitor) = 0;
//};
//
//// 具体的元素类 ElementA
//class ElementA : public Element {
//public:
//    void accept(Visitor* visitor) override {
//        visitor->visitElementA(this);
//    }
//};
//
//// 具体的元素类 ElementB
//class ElementB : public Element {
//public:
//    void accept(Visitor* visitor) override {
//        visitor->visitElementB(this);
//    }
//};
//
//int main() {
//    // 创建访问者和元素
//    ConcreteVisitor visitor;
//    std::vector<Element*> elements = { new ElementA(), new ElementB() };
//
//    // 对每个元素应用访问者操作
//    for (Element* element : elements) {
//        element->accept(&visitor);
//    }
//
//    // 释放内存
//    for (Element* element : elements) {
//        delete element;
//    }
//
//    return 0;
//}




//#include <iostream>
//#include <string>
//#include <vector>
//
//// 前向声明 Colleague 类
//class Colleague;
//
//// 定义中介者 Mediator 抽象类
//class Mediator {
//public:
//    virtual void sendMessage(const Colleague* colleague, const std::string& message) const = 0;
//};
//
//// 定义同事类 Colleague 抽象类
//class Colleague {
//public:
//    explicit Colleague(Mediator* mediator) : mediator(mediator) {}
//
//    virtual void sendMessage(const std::string& message) const = 0;
//    virtual void receiveMessage(const std::string& message) const = 0;
//
//protected:
//    Mediator* mediator;
//};
//
//// 定义具体中介者 ConcreteMediator 类
//class ConcreteMediator : public Mediator {
//public:
//    void addColleague(Colleague* colleague) {
//        colleagues.push_back(colleague);
//    }
//
//    void sendMessage(const Colleague* colleague, const std::string& message) const override {
//        for (const auto& col : colleagues) {
//            if (col != colleague) {
//                col->receiveMessage(message);
//            }
//        }
//    }
//
//private:
//    std::vector<Colleague*> colleagues;
//};
//
//// 定义具体同事类 ConcreteColleagueA
//class ConcreteColleagueA : public Colleague {
//public:
//    using Colleague::Colleague;
//
//    void sendMessage(const std::string& message) const override {
//        mediator->sendMessage(this, message);
//    }
//
//    void receiveMessage(const std::string& message) const override {
//        std::cout << "ConcreteColleagueA received: " << message << std::endl;
//    }
//};
//
//// 定义具体同事类 ConcreteColleagueB
//class ConcreteColleagueB : public Colleague {
//public:
//    using Colleague::Colleague;
//
//    void sendMessage(const std::string& message) const override {
//        mediator->sendMessage(this, message);
//    }
//
//    void receiveMessage(const std::string& message) const override {
//        std::cout << "ConcreteColleagueB received: " << message << std::endl;
//    }
//};
//
//int main() {
//    // 创建具体中介者
//    ConcreteMediator mediator;
//
//    // 创建具体同事对象，并将它们注册到中介者中
//    ConcreteColleagueA colleagueA(&mediator);
//    ConcreteColleagueB colleagueB(&mediator);
//    mediator.addColleague(&colleagueA);
//    mediator.addColleague(&colleagueB);
//
//    // 同事对象之间发送消息
//    colleagueA.sendMessage("Hello from ColleagueA");
//    colleagueB.sendMessage("Hi from ColleagueB");
//
//    return 0;
//}




#include <iostream>
#include <vector>

// 定义一个抽象迭代器接口
template<typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
};

// 具体的迭代器实现
template<typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::vector<T> data;
    size_t position;
public:
    ConcreteIterator(const std::vector<T>& data) : data(data), position(0) {}

    bool hasNext() const override {
        return position < data.size();
    }

    T next() override {
        if (!hasNext()) {
            throw std::out_of_range("Iterator out of range");
        }
        return data[position++];
    }
};

// 定义可迭代的集合接口
template<typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() const = 0;
    virtual ~Aggregate() {}
};

// 具体的集合实现
template<typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    std::vector<T> data;
public:
    ConcreteAggregate(std::vector<T> data) : data(data) {}

    Iterator<T>* createIterator() const override {
        return new ConcreteIterator<T>(data);
    }
};

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    ConcreteAggregate<int> aggregate(vec);
    Iterator<int>* iter = aggregate.createIterator();

    std::cout << "Iterating through the collection:" << std::endl;
    while (iter->hasNext()) {
        std::cout << iter->next() << " ";
    }
    std::cout << std::endl;

    delete iter;

    return 0;
}
