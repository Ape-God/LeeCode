//#include <iostream>
//#include <string>
//#include <memory>
//
//// �����Ʒ������
//class Vehicle {
//public:
//    virtual void drive() const = 0;
//    virtual ~Vehicle() {}
//};
//
//// �����Ʒ������
//class Car : public Vehicle {
//public:
//    void drive() const override {
//        std::cout << "Car is driving." << std::endl;
//    }
//};
//
//// �����Ʒ��Ħ�г�
//class Motorcycle : public Vehicle {
//public:
//    void drive() const override {
//        std::cout << "Motorcycle is driving." << std::endl;
//    }
//};
//
//// �����ࣺ��������
//class VehicleFactory {
//public:
//    // ��̬���������ݴ���������ַ�����������Ӧ�ĳ�������
//    static Vehicle* createVehicle(const std::string& type) {
//        if (type == "Car") {
//            return new Car();
//        }
//        else if (type == "Motorcycle") {
//            return new Motorcycle();
//        }
//        // �����������Ͳ�ƥ�䣬�򷵻� nullptr
//        return nullptr;
//    }
//};
//
//int main() {
//    // �ͻ��˴���
//    // ����һ��ָ�� Vehicle ��ָ�룬���ڽ��չ��������Ķ���
//    Vehicle* vehicle = nullptr;
//
//    // ���Դ�������
//    std::cout << "Creating Car..." << std::endl;
//    vehicle = VehicleFactory::createVehicle("Car");
//    if (vehicle) {
//        vehicle->drive();  // ���������� drive ����
//    }
//    else {
//        std::cout << "Failed to create Car." << std::endl;
//    }
//
//    // ���Դ���Ħ�г�
//    std::cout << "\nCreating Motorcycle..." << std::endl;
//    vehicle = VehicleFactory::createVehicle("Motorcycle");
//    if (vehicle) {
//        vehicle->drive();  // ����Ħ�г��� drive ����
//    }
//    else {
//        std::cout << "Failed to create Motorcycle." << std::endl;
//    }
//
//    // �ͷ�֮ǰ�����ĳ�������
//    delete vehicle;
//
//    return 0;
//}




//��������ģʽ

//#include <iostream>
//#include <memory>
//
//// �����Ʒ������
//class Vehicle {
//public:
//    virtual void drive() const = 0;
//    virtual ~Vehicle() {}
//};
//
//// �����Ʒ������
//class Car : public Vehicle {
//public:
//    void drive() const override {
//        std::cout << "Car is driving on the highway." << std::endl;
//    }
//};
//
//// �����Ʒ��Ħ�г�
//class Motorcycle : public Vehicle {
//public:
//    void drive() const override {
//        std::cout << "Motorcycle is driving on the street." << std::endl;
//    }
//};
//
//// ���󹤳�����������
//class VehicleFactory {
//public:
//    virtual std::unique_ptr<Vehicle> createVehicle() const = 0;
//    virtual ~VehicleFactory() {}
//};
//
//// ���幤������������
//class CarFactory : public VehicleFactory {
//public:
//    std::unique_ptr<Vehicle> createVehicle() const override {
//        return std::make_unique<Car>();
//    }
//};
//
//// ���幤����Ħ�г�����
//class MotorcycleFactory : public VehicleFactory {
//public:
//    std::unique_ptr<Vehicle> createVehicle() const override {
//        return std::make_unique<Motorcycle>();
//    }
//};
//
//// �ͻ��˴���
//int main() {
//    // ʹ������ָ�������Դ
//    std::unique_ptr<VehicleFactory> factory;
//
//    // ��Ҫ��������
//    factory = std::make_unique<CarFactory>();
//    factory->createVehicle()->drive();
//
//    // ��Ҫ����Ħ�г�
//    factory = std::make_unique<MotorcycleFactory>();
//    factory->createVehicle()->drive();
//
//    return 0;
//}



//#include <iostream>
//#include <memory>
//
//// �����Ʒ����ɫ
//class Color {
//public:
//    virtual void applyColor() const = 0;
//    virtual ~Color() {}
//};
//
//// �����Ʒ����ɫ
//class Red : public Color {
//public:
//    void applyColor() const override {
//        std::cout << "Applying Red color." << std::endl;
//    }
//};
//
//// �����Ʒ����ɫ
//class Blue : public Color {
//public:
//    void applyColor() const override {
//        std::cout << "Applying Blue color." << std::endl;
//    }
//};
//
//// �����Ʒ����״
//class Shape {
//public:
//    virtual void applyShape() const = 0;
//    virtual ~Shape() {}
//};
//
//// �����Ʒ��Բ��
//class Circle : public Shape {
//public:
//    void applyShape() const override {
//        std::cout << "Applying Circle shape." << std::endl;
//    }
//};
//
//// �����Ʒ��������
//class Square : public Shape {
//public:
//    void applyShape() const override {
//        std::cout << "Applying Square shape." << std::endl;
//    }
//};
//
//// ���󹤳�����������
//class ArtFactory {
//public:
//    virtual std::unique_ptr<Color> createColor() const = 0;
//    virtual std::unique_ptr<Shape> createShape() const = 0;
//    virtual ~ArtFactory() {}
//};
//
//// ���幤�����ִ���������
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
//// ���幤����ӡ����������
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
//// �ͻ��˴���
//int main() {
//    std::unique_ptr<ArtFactory> factory;
//
//    // ʹ���ִ���������
//    factory = std::make_unique<ModernArtFactory>();
//    auto color = factory->createColor();
//    auto shape = factory->createShape();
//    color->applyColor();
//    shape->applyShape();
//
//    // ʹ��ӡ����������
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
//    // ˽�й��캯������ֹ�ⲿͨ��new����ʵ��
//    Singleton() {}
//
//public:
//    // ��ֹ���ƹ��캯��
//    Singleton(const Singleton&) = delete;
//    // ��ֹ��ֵ����
//    Singleton& operator=(const Singleton&) = delete;
//
//    // �ṩһ����̬���з��������ڻ�ȡ���Ψһʵ��
//    static Singleton& getInstance() {
//        static Singleton instance; // �ֲ���̬������ȷ���̰߳�ȫ��������
//        return instance;
//    }
//
//    void doSomething() const {
//        std::cout << "Doing something important." << std::endl;
//    }
//};
//
//int main() {
//    // ��ȡ������������ã������÷���
//    Singleton& singleton = Singleton::getInstance();
//    singleton.doSomething();
//
//    // �ٴλ�ȡ������������ã��⽫����ͬһ��ʵ��
//    Singleton& anotherSingleton = Singleton::getInstance();
//    anotherSingleton.doSomething();
//
//    // ��ӡ��ַ��֤�����λ�ȡ����ͬһ��ʵ��
//    std::cout << "Singleton instance address: " << &singleton << std::endl;
//    std::cout << "Another singleton instance address: " << &anotherSingleton << std::endl;
//
//    return 0;
//}



//#include <iostream>
//#include <string>
//
//// ��Ʒ��ɫ������
//class Car {
//private:
//    std::string engine;
//    std::string tires;
//    std::string bodyColor;
//
//public:
//    // ���캯��˽�л���ȷ��ֻ��ͨ��������������
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
//// �������ӿ�
//class CarBuilder {
//public:
//    virtual ~CarBuilder() {}
//    virtual CarBuilder* setEngine(const std::string& engine) = 0;
//    virtual CarBuilder* setTires(const std::string& tires) = 0;
//    virtual CarBuilder* setBodyColor(const std::string& color) = 0;
//    virtual Car* getCar() = 0;
//};
//
//// ����������
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
//// ָ����
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
//// �ͻ��˴���
//int main() {
//    CarBuilder* builder = new ConcreteCarBuilder();
//    CarDirector director;
//    Car* car = director.constructCar(builder);
//    car->showSpecs(); // ��ӡ�������
//
//    delete car; // ������Դ
//    delete builder;
//    return 0;
//}





//#include <iostream>
//#include <memory>
//
//// ԭ�ͽӿ�
//class Animal {
//public:
//    virtual ~Animal() {}
//
//    // ��¡����
//    virtual std::unique_ptr<Animal> clone() const = 0;
//
//    // ��ʾ������Ϣ
//    virtual void showInfo() const = 0;
//};
//
//// ����ԭ�ͣ���
//class Sheep : public Animal {
//private:
//    std::string name;
//
//public:
//    Sheep(const std::string& name) : name(name) {}
//
//    // ��¡��
//    std::unique_ptr<Animal> clone() const override {
//        return std::make_unique<Sheep>(name);
//    }
//
//    // ��ʾ�����Ϣ
//    void showInfo() const override {
//        std::cout << "Sheep: " << name << std::endl;
//    }
//};
//
//// �ͻ��˴���
//int main() {
//    // ����һ�����ʵ��
//    std::unique_ptr<Animal> original = std::make_unique<Sheep>("Little Sheep");
//
//    // ��¡��
//    std::unique_ptr<Animal> cloned = original->clone();
//
//    // ��ӡԭʼ�����Ϣ
//    original->showInfo();
//
//    // ��ӡ��¡�����Ϣ
//    cloned->showInfo();
//
//    return 0;
//}



////�����������
//#include <iostream>
//
//// ����һ��Ŀ��ӿ�
//class Target {
//public:
//    virtual void request() = 0;
//    virtual ~Target() {}
//};
//
//// ����һ����������������
//class Adaptee {
//public:
//    void specificRequest() {
//        std::cout << "Executing specific request in Adaptee" << std::endl;
//    }
//};
//
//// ��������ģʽ
//class Adapter : public Target {
//private:
//    Adaptee adaptee;
//public:
//    void request() override {
//        // ���������ߵķ���
//        adaptee.specificRequest();
//    }
//};
//
//int main() {
//    // ���������߶���
//    Adaptee adapteeObj;
//
//    // �������������󣬲�������ΪĿ��ӿڵĶ���ʹ��
//    Target* adapter = new Adapter();
//
//    // ʹ����������ִ������
//    std::cout << "Client: I can use the target via adapter: " << std::endl;
//    adapter->request();
//
//    delete adapter; // ���������ڴ�
//    return 0;
//}




//#include <iostream>
//
//// ����һ��Ŀ��ӿ�
//class Target {
//public:
//    virtual void request() = 0;
//    virtual ~Target() {}
//};
//
//// ����һ����������������
//class Adaptee {
//public:
//    void specificRequest() {
//        std::cout << "Adaptee: Executing specific request" << std::endl;
//    }
//};
//
//// ����������
//class Adapter : public Target {
//private:
//    Adaptee adaptee; // ����һ��Adaptee����
//
//public:
//    // ʵ��Target�ӿڵ�request����
//    void request() override {
//        // ��Adaptee��specificRequest��������ΪTarget�ӿڵ�request����
//        adaptee.specificRequest();
//    }
//};
//
//int main() {
//    // ����Adaptee����
//    Adaptee adapteeObj;
//
//    // ����Adapter�������ڲ�����һ��Adaptee����
//    Adapter adapterObj;
//
//    // ͨ��Adapter�������request����
//    std::cout << "Client: I can use the target via adapter: " << std::endl;
//    adapterObj.request();
//
//    return 0;
//}




//#include <iostream>
//
//// Ŀ��ӿ�
//class Target {
//public:
//    virtual void request() = 0;
//    virtual ~Target() {}
//};
//
//// �����߽ӿ�
//class Adaptee {
//public:
//    void specificRequest() {
//        std::cout << "Adaptee: Doing something specific" << std::endl;
//    }
//};
//
//// �ӿ�������
//class Adapter : public Target {
//private:
//    Adaptee adaptee;
//
//public:
//    Adapter(Adaptee& adaptee_) : adaptee(adaptee_) {}
//
//    void request() override {
//        // ��Adaptee��specificRequest��������ΪTarget�ӿڵ�request����
//        adaptee.specificRequest();
//    }
//};
//
//int main() {
//    // ����Adaptee����
//    Adaptee adapteeObj;
//
//    // ����Adapter��������Adaptee������Ϊ����
//    Adapter adapter(adapteeObj);
//
//    // ͨ��Adapter�������request����
//    std::cout << "Client: I can use the target via adapter: " << std::endl;
//    adapter.request();
//
//    return 0;
//}


//
//#include <iostream>
//
//// �������
//class Component {
//public:
//    virtual void operation() = 0; // ����һ���ӿڷ���
//    virtual ~Component() {} // ����������ȷ�����������������������
//};
//
//// �������
//class ConcreteComponent : public Component {
//public:
//    void operation() override {
//        std::cout << "ConcreteComponent: ��������" << std::endl;
//    }
//};
//
//// ����װ������
//class Decorator : public Component {
//protected:
//    Component* wrappedComponent; // ���������ָ��
//
//public:
//    Decorator(Component* component) : wrappedComponent(component) {}
//
//    // ������дoperation����
//    void operation() override {
//        if (wrappedComponent != nullptr) {
//            wrappedComponent->operation();
//        }
//    }
//
//    // ����������
//    virtual ~Decorator() {}
//};
//
//// ����װ����A
//class ConcreteDecoratorA : public Decorator {
//public:
//    ConcreteDecoratorA(Component* component) : Decorator(component) {}
//
//    void operation() override {
//        if (wrappedComponent != nullptr) {
//            wrappedComponent->operation(); // ���ñ�װ���ߵķ���
//            addedBehaviorA(); // ����µ���Ϊ
//        }
//    }
//
//    void addedBehaviorA() {
//        std::cout << "ConcreteDecoratorA: ��ӵ���ΪA" << std::endl;
//    }
//};
//
//// ����װ����B
//class ConcreteDecoratorB : public Decorator {
//public:
//    ConcreteDecoratorB(Component* component) : Decorator(component) {}
//
//    void operation() override {
//        if (wrappedComponent != nullptr) {
//            wrappedComponent->operation(); // ���ñ�װ���ߵķ���
//            addedBehaviorB(); // ����µ���Ϊ
//        }
//    }
//
//    void addedBehaviorB() {
//        std::cout << "ConcreteDecoratorB: ��ӵ���ΪB" << std::endl;
//    }
//};
//
//int main() {
//    // �����������
//    ConcreteComponent* c = new ConcreteComponent();
//
//    // ����װ����A��B����װ�ξ������
//    ConcreteDecoratorA* decoratorA = new ConcreteDecoratorA(c);
//    ConcreteDecoratorB* decoratorB = new ConcreteDecoratorB(decoratorA);
//
//    // ִ�в�����������װ������ӵ���Ϊ
//    std::cout << "װ��ǰ:" << std::endl;
//    c->operation();
//
//    std::cout << "\nʹ��DecoratorAװ�κ�:" << std::endl;
//    decoratorA->operation();
//
//    std::cout << "\nʹ��DecoratorB��һ��װ�κ�:" << std::endl;
//    decoratorB->operation();
//
//    // ������Դ
//    delete decoratorB;
//    delete decoratorA;
//    delete c;
//
//    return 0;
//}





//#include <iostream>
//
//// ����һ���ӿڣ������������ί���඼����ʵ����
//class ImageLoader {
//public:
//    virtual void load() = 0;
//    virtual ~ImageLoader() {}
//};
//
//// ί���࣬ʵ��ִ�м��ز�������
//class RealImageLoader : public ImageLoader {
//public:
//    void load() override {
//        std::cout << "RealImageLoader: Loading image..." << std::endl;
//        // ִ�м���ͼƬ�Ĵ���
//    }
//};
//
//// �����࣬�����˶���Ĺ���
//class ImageLoaderProxy : public ImageLoader {
//private:
//    ImageLoader* realLoader; // ָ��ί�����ָ��
//
//public:
//    ImageLoaderProxy(ImageLoader* loader) : realLoader(loader) {}
//
//    void load() override {
//        // �����������������Ӷ���Ĺ���
//        std::cout << "ImageLoaderProxy: Pre-loading setup..." << std::endl;
//
//        // ����ί����ķ���
//        realLoader->load();
//
//        // ������������Ӽ��غ�Ķ��⹦��
//        std::cout << "ImageLoaderProxy: Post-loading cleanup..." << std::endl;
//    }
//};
//
//int main() {
//    // ����ί�ж���
//    RealImageLoader* realLoader = new RealImageLoader();
//
//    // ����������󣬽�ί�ж��󴫵ݸ�����
//    ImageLoaderProxy* proxy = new ImageLoaderProxy(realLoader);
//
//    // ͨ������������load����
//    std::cout << "Using proxy to load image:" << std::endl;
//    proxy->load();
//
//    // ������Դ
//    delete proxy;
//    delete realLoader;
//
//    return 0;
//}



//#include <iostream>
//
//// ����һ���ӿڣ������������ί���඼����ʵ����
//class ImageLoader {
//public:
//    virtual void load() = 0;
//    virtual ~ImageLoader() {}
//};
//
//// ί���࣬ʵ��ִ�м��ز�������
//class RealImageLoader : public ImageLoader {
//public:
//    void load() override {
//        std::cout << "RealImageLoader: Loading image..." << std::endl;
//        // ִ�м���ͼƬ�Ĵ���
//    }
//};
//
//// �����࣬�����˶���Ĺ���
//class ImageLoaderProxy : public ImageLoader {
//private:
//    ImageLoader* realLoader; // ָ��ί�����ָ��
//
//public:
//    ImageLoaderProxy(ImageLoader* loader) : realLoader(loader) {}
//
//    void load() override {
//        // �����������������Ӷ���Ĺ���
//        std::cout << "ImageLoaderProxy: Pre-loading setup..." << std::endl;
//
//        // ����ί����ķ���
//        realLoader->load();
//
//        // ������������Ӽ��غ�Ķ��⹦��
//        std::cout << "ImageLoaderProxy: Post-loading cleanup..." << std::endl;
//    }
//};
//
//int main() {
//    // ����ί�ж���
//    RealImageLoader* realLoader = new RealImageLoader();
//
//    // ����������󣬽�ί�ж��󴫵ݸ�����
//    ImageLoaderProxy* proxy = new ImageLoaderProxy(realLoader);
//
//    // ͨ������������load����
//    std::cout << "Using proxy to load image:" << std::endl;
//    proxy->load();
//
//    // ������Դ
//    delete proxy;
//    delete realLoader;
//
//    return 0;
//}



////��̬����
//#include <iostream>
//#include <memory>
//
//// ����һ���ӿڣ������������ί���඼����ʵ����
//class ImageLoader {
//public:
//    virtual void load() = 0;
//    virtual ~ImageLoader() {}
//};
//
//// ί���࣬ʵ��ִ�м��ز�������
//class RealImageLoader : public ImageLoader {
//public:
//    void load() override {
//        std::cout << "RealImageLoader: Loading image..." << std::endl;
//        // ִ�м���ͼƬ�Ĵ���
//    }
//};
//
//// �����࣬�����˶���Ĺ���
//class ImageLoaderProxy : public ImageLoader {
//private:
//    std::unique_ptr<ImageLoader> realLoader; // ָ��ί���������ָ��
//
//public:
//    ImageLoaderProxy(std::unique_ptr<ImageLoader> loader) : realLoader(std::move(loader)) {}
//
//    void load() override {
//        // �����������������Ӷ���Ĺ���
//        std::cout << "ImageLoaderProxy: Pre-loading setup..." << std::endl;
//
//        // ����ί����ķ���
//        realLoader->load();
//
//        // ������������Ӽ��غ�Ķ��⹦��
//        std::cout << "ImageLoaderProxy: Post-loading cleanup..." << std::endl;
//    }
//};
//
//// ��̬��������Ĺ�������
//std::unique_ptr<ImageLoader> createDynamicProxy(std::unique_ptr<ImageLoader>&& realLoader) {
//    return std::make_unique<ImageLoaderProxy>(std::move(realLoader));
//}
//
//int main() {
//    // ����ί�ж���
//    auto realLoader = std::make_unique<RealImageLoader>();
//
//    // ��̬�����������
//    auto proxy = createDynamicProxy(std::move(realLoader));
//
//    // ͨ������������load����
//    std::cout << "Using proxy to load image:" << std::endl;
//    proxy->load();
//
//    return 0;
//}




//#include <iostream>
//#include <functional>
//#include <map>
//
//// ����һ���ӿڣ������������ί���඼����ʵ����
//class ISubject {
//public:
//    virtual void request() = 0;
//    virtual ~ISubject() {}
//};
//
//// ί���࣬ʵ��ִ�������������
//class RealSubject : public ISubject {
//public:
//    void request() override {
//        std::cout << "RealSubject: Handling request..." << std::endl;
//    }
//};
//
//// ������ģ�壬���Դ����κ�ʵ����ISubject�ӿڵ���
//template <typename T>
//class SubjectProxy : public ISubject {
//private:
//    T* realSubject; // ָ��ί�����ָ��
//
//public:
//    SubjectProxy(T* subject) : realSubject(subject) {}
//
//    void request() override {
//        // �����������������Ӷ���Ĺ���
//        std::cout << "SubjectProxy: Before request" << std::endl;
//
//        // ����ί����ķ���
//        realSubject->request();
//
//        // ������������������Ķ��⹦��
//        std::cout << "SubjectProxy: After request" << std::endl;
//    }
//};
//
//int main() {
//    // ����ί�ж���
//    RealSubject* realSubject = new RealSubject();
//
//    // ����������󣬴���RealSubject
//    ISubject* proxy = new SubjectProxy<RealSubject>(realSubject);
//
//    // ͨ������������request����
//    std::cout << "Using proxy:" << std::endl;
//    proxy->request();
//
//    // ������Դ
//    delete proxy;
//    delete realSubject;
//
//    return 0;
//}



//���ģʽ
//#include <iostream>
//
//// ��ϵͳ��A
//class SubSystemA {
//public:
//    void operationA() {
//        std::cout << "SubSystemA: Operation A" << std::endl;
//    }
//};
//
//// ��ϵͳ��B
//class SubSystemB {
//public:
//    void operationB() {
//        std::cout << "SubSystemB: Operation B" << std::endl;
//    }
//};
//
//// ��ϵͳ��C
//class SubSystemC {
//public:
//    void operationC() {
//        std::cout << "SubSystemC: Operation C" << std::endl;
//    }
//};
//
//// �����
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



////�Ž�ģʽ
//#include <iostream>
//#include <string>
//
//// ������״��
//class Shape {
//public:
//    virtual ~Shape() {}
//    virtual void draw() const = 0;
//};
//
//// ����ʵ����
//class ShapeImpl {
//public:
//    virtual ~ShapeImpl() {}
//    virtual void applyColor() const = 0;
//};
//
//// ������״��
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
//// ����ʵ����
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
//// �ͻ��˴���
//int main() {
//    Shape* shape = new Circle(new RedCircle());
//    shape->draw();
//
//    delete shape; // �����ڴ�
//
//    shape = new Circle(new BlueCircle());
//    shape->draw();
//
//    delete shape; // �����ڴ�
//
//    return 0;
//}



////���ģʽ
//#include <iostream>
//#include <vector>
//#include <memory>
//
//// ���󹹼�
//class Component {
//public:
//    virtual void operation() = 0;
//    virtual ~Component() {}
//};
//
//// Ҷ�ڵ�
//class Leaf : public Component {
//public:
//    void operation() override {
//        std::cout << "Leaf is performing operation" << std::endl;
//    }
//};
//
//// ��Ͻڵ�
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
//// �ͻ��˴���
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



////��Ԫģʽ
//#include <iostream>
//#include <unordered_map>
//#include <memory>
//
//// ��Ԫ�ӿ�
//class Flyweight {
//public:
//    virtual ~Flyweight() {}
//    virtual void operation(std::string extrinsicState) = 0;
//};
//
//// ������Ԫ��
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
//// ��Ԫ����
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
//// �ͻ��˴���
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


////����ģʽ
//#include <iostream>
//#include <string>
//
//// ���Խӿ�
//class Strategy {
//public:
//    virtual ~Strategy() {}
//    virtual void execute() const = 0;
//};
//
//// �������A
//class ConcreteStrategyA : public Strategy {
//public:
//    void execute() const override {
//        std::cout << "Executing ConcreteStrategyA" << std::endl;
//    }
//};
//
//// �������B
//class ConcreteStrategyB : public Strategy {
//public:
//    void execute() const override {
//        std::cout << "Executing ConcreteStrategyB" << std::endl;
//    }
//};
//
//// ������
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
//// �ͻ��˴���
//int main() {
//    // ���������Ĳ���ʼ������
//    Context context(new ConcreteStrategyA());
//    context.executeStrategy();  // ִ�в���A
//
//    // �ı����
//    context.setStrategy(new ConcreteStrategyB());
//    context.executeStrategy();  // ִ�в���B
//
//    return 0;
//}



//ģ��ģʽ
//#include <iostream>
//#include <string>
//
//// ������
//class AbstractClass {
//public:
//    // ģ�巽��
//    void templateMethod() {
//        stepOne();
//        stepTwo();
//        stepThree();
//    }
//
//protected:
//    // �������裬�������ʵ��
//    virtual void stepOne() = 0;
//    virtual void stepTwo() = 0;
//    virtual void stepThree() = 0;
//};
//
//// ������A
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
//// ������B
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
//// �ͻ��˴���
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
//// �۲��߽ӿ�
//class Observer {
//public:
//    virtual ~Observer() {}
//    virtual void update() = 0; // ����֪ͨʱ���õķ���
//};
//
//// ����ӿ�
//class Subject {
//private:
//    std::vector<Observer*> observers; // �۲����б�
//
//public:
//    virtual ~Subject() {}
//
//    void attach(Observer* observer) {
//        observers.push_back(observer); // ��ӹ۲���
//    }
//
//    void detach(Observer* observer) {
//        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end()); // ɾ���۲���
//    }
//
//    void notify() {
//        for (Observer* observer : observers) {
//            observer->update(); // ֪ͨ���й۲���
//        }
//    }
//};
//
//// ����۲���
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
//// ��������
//class ConcreteSubject : public Subject {
//private:
//    std::string state;
//
//public:
//    void setState(const std::string& state) {
//        this->state = state;
//        notify(); // ���״̬�ı䣬֪ͨ���й۲���
//    }
//
//    std::string getState() const {
//        return state;
//    }
//};
//
//// �ͻ��˴���
//int main() {
//    ConcreteSubject subject;
//
//    ConcreteObserver observer1("1");
//    ConcreteObserver observer2("2");
//
//    subject.attach(&observer1);
//    subject.attach(&observer2);
//
//    subject.setState("New State 1"); // ֪ͨ���й۲���
//
//    subject.detach(&observer1);
//
//    subject.setState("New State 2"); // ֻ��observer2�ᱻ֪ͨ
//
//    return 0;
//}





//#include <iostream>
//#include <string>
//
//// ����ӿ�
//class Request {
//public:
//    std::string message;
//    Request(const std::string& msg) : message(msg) {}
//};
//
//// �������ӿ�
//class Handler {
//public:
//    virtual ~Handler() {}
//    virtual void HandleRequest(Request* request) = 0;
//    virtual void SetNext(Handler* next) = 0;
//};
//
//// ���崦����
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
//// �ͻ��˴���
//int main() {
//    Handler* handlerA = new ConcreteHandlerA();
//    Handler* handlerB = new ConcreteHandlerB();
//
//    handlerA->SetNext(handlerB); // ��B����ΪA�ĺ��
//
//    Request* request1 = new Request("Request A");
//    Request* request2 = new Request("Request B");
//    Request* request3 = new Request("Request C");
//
//    handlerA->HandleRequest(request1); // �����󴫵ݸ�A��A����
//    handlerA->HandleRequest(request2); // �����󴫵ݸ�A��A���ݸ�B��B����
//    handlerA->HandleRequest(request3); // �����󴫵ݸ�A��Ȼ�󴫵ݸ�B��B������
//
//    delete request1;
//    delete request2;
//    delete request3;
//    delete handlerA;
//    delete handlerB;
//
//    return 0;
//}



////����ģʽ
//#include <iostream>
//#include <string>
//#include <memory>
//
//// �����ߣ�Receiver��
//class Receiver {
//public:
//    virtual ~Receiver() {}
//    virtual void Action() = 0;
//};
//
//// ���������
//class ConcreteReceiver : public Receiver {
//public:
//    void Action() override {
//        std::cout << "Action has been executed." << std::endl;
//    }
//};
//
//// ����ӿڣ�Command��
//class Command {
//public:
//    virtual ~Command() {}
//    virtual void Execute() = 0;
//    virtual void Undo() = 0; // ��ӳ�������
//};
//
//// ��������
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
//// �����ߣ�Invoker��
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
//// �ͻ��˴���
//int main() {
//    // ����������
//    auto receiver = std::make_unique<ConcreteReceiver>();
//
//    // ������������
//    auto command = std::make_unique<ConcreteCommand>(std::move(receiver));
//
//    // ����������
//    Invoker invoker;
//
//    // ��������
//    invoker.SetCommand(std::move(command));
//
//    // ִ������
//    invoker.ExecuteCommand();
//
//    // ��������
//    invoker.UndoCommand();
//
//    return 0;
//}




////״̬ģʽ
//#include <iostream>
//#include <memory>
//
//// ״̬�ӿ�
//class State {
//public:
//    virtual ~State() {}
//    virtual void Handle() = 0;
//};
//
//// ����״̬��A
//class ConcreteStateA : public State {
//public:
//    void Handle() override {
//        std::cout << "Handling request in ConcreteStateA" << std::endl;
//    }
//};
//
//// ����״̬��B
//class ConcreteStateB : public State {
//public:
//    void Handle() override {
//        std::cout << "Handling request in ConcreteStateB" << std::endl;
//    }
//};
//
//// �����Ļ�����
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
//// �ͻ��˴���
//int main() {
//    // ����״̬����
//    auto stateA = std::make_unique<ConcreteStateA>();
//    auto stateB = std::make_unique<ConcreteStateB>();
//
//    // ���������Ļ�������
//    Context context;
//
//    // ����״̬ΪA����������
//    context.SetState(std::move(stateA));
//    context.Request();
//
//    // ����״̬ΪB����������
//    context.SetState(std::move(stateB));
//    context.Request();
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//
//// �˴�����������Ԫ���࣬�ֱ��� ElementA �� ElementB
//class ElementA;
//class ElementB;
//
//// ����һ������������� Visitor
//class Visitor {
//public:
//    virtual void visitElementA(ElementA* element) = 0;
//    virtual void visitElementB(ElementB* element) = 0;
//};
//
//// ����ķ������� ConcreteVisitor��ʵ���˶�����Ԫ�صķ��ʲ���
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
//// ����һ������Ԫ���� Element
//class Element {
//public:
//    virtual void accept(Visitor* visitor) = 0;
//};
//
//// �����Ԫ���� ElementA
//class ElementA : public Element {
//public:
//    void accept(Visitor* visitor) override {
//        visitor->visitElementA(this);
//    }
//};
//
//// �����Ԫ���� ElementB
//class ElementB : public Element {
//public:
//    void accept(Visitor* visitor) override {
//        visitor->visitElementB(this);
//    }
//};
//
//int main() {
//    // ���������ߺ�Ԫ��
//    ConcreteVisitor visitor;
//    std::vector<Element*> elements = { new ElementA(), new ElementB() };
//
//    // ��ÿ��Ԫ��Ӧ�÷����߲���
//    for (Element* element : elements) {
//        element->accept(&visitor);
//    }
//
//    // �ͷ��ڴ�
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
//// ǰ������ Colleague ��
//class Colleague;
//
//// �����н��� Mediator ������
//class Mediator {
//public:
//    virtual void sendMessage(const Colleague* colleague, const std::string& message) const = 0;
//};
//
//// ����ͬ���� Colleague ������
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
//// ��������н��� ConcreteMediator ��
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
//// �������ͬ���� ConcreteColleagueA
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
//// �������ͬ���� ConcreteColleagueB
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
//    // ���������н���
//    ConcreteMediator mediator;
//
//    // ��������ͬ�¶��󣬲�������ע�ᵽ�н�����
//    ConcreteColleagueA colleagueA(&mediator);
//    ConcreteColleagueB colleagueB(&mediator);
//    mediator.addColleague(&colleagueA);
//    mediator.addColleague(&colleagueB);
//
//    // ͬ�¶���֮�䷢����Ϣ
//    colleagueA.sendMessage("Hello from ColleagueA");
//    colleagueB.sendMessage("Hi from ColleagueB");
//
//    return 0;
//}




#include <iostream>
#include <vector>

// ����һ������������ӿ�
template<typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
};

// ����ĵ�����ʵ��
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

// ����ɵ����ļ��Ͻӿ�
template<typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() const = 0;
    virtual ~Aggregate() {}
};

// ����ļ���ʵ��
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
