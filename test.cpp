#include <iostream>
#include <vector>
#include <memory>

// ��Ԫ������
class FriendClass;

// ѧϰ�õ���
class LearningClass {
private:
    std::string name; // ˽�г�Ա����
    int age;          // ˽�г�Ա����

public:
    // ���캯��������name��age����ֵ��˽�б���name(name)�������˼�ǲ���name����˽�б���name����age(age) 
    LearningClass(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Constructor called for " << name << std::endl;
    }

    // �����������ͷ��ڴ� 
    ~LearningClass() {
        std::cout << "Destructor called for " << name << std::endl;
    }

    // ���г�Ա��������������
    void setName(const std::string& newName) {
        name = newName;
    }

    // ���г�Ա��������������
    void setAge(int newAge) {
        age = newAge;
    }

    // ���г�Ա��������ȡ����
    std::string getName() const {
        return name;
    }

    // ���г�Ա��������ȡ����
    int getAge() const {
        return age;
    }

    // ������Ա��������ӡ��Ϣ
    void printInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // ��Ԫ��������
    friend void displayInfo(const LearningClass& obj);
    friend void displayInfoFromFriend(const LearningClass& obj);
    friend class FriendClass;
};

// ��Ԫ��������
void displayInfo(const LearningClass& obj) {
    std::cout << "Friend function displayInfo called." << std::endl;
    obj.printInfo();
}

// ��һ����Ԫ������λ�����ⲿ�����Է���LearningClass��˽�г�Ա
void displayInfoFromFriend(const LearningClass& obj) {
    std::cout << "Friend function displayInfoFromFriend called. Name: " << obj.name << ", Age: " << obj.age << std::endl;
}

// ��Ԫ�ඨ��
class FriendClass {
public:
    void accessLearningClass(const LearningClass& obj) {
        std::cout << "Friend class FriendClass accessing LearningClass members." << std::endl;
        std::cout << "Name: " << obj.name << ", Age: " << obj.age << std::endl;
    }
};

// ��������
void printNumbers(const std::vector<int>& nums) {
	int num = 0, i = 0;
    for (i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

// ��resource���� 
class Resource {
public:
    Resource() { std::cout << "Resource created\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};



int main() {
	int i = 0;
	
    LearningClass obj("Kimi", 30); //���ʵ���� 
    obj.printInfo(); // ���ù��г�Ա����
    displayInfo(obj); // ������Ԫ����

    FriendClass friendObj;
    friendObj.accessLearningClass(obj); // ��Ԫ�����LearningClass��˽�г�Ա

    // ����һ���������洢����
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // ʹ��forѭ����������
    for (i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 3) {
            std::cout << "Found 3 at position " << i << std::endl;
            break; // �ҵ�3�������ѭ��
        }
    }

    // ���ú�����ӡ�����е�����
    std::cout << "Vector contains: ";
    printNumbers(numbers);

	//����ָ�붨��std::unique_ptr<Resource>��<Resource>��ʾָ��ָ�����Resource��
	//ָ������Ϊptr��new Resource()��newΪ��̬�����ڴ棬Resource()Ϊ�����ʵ���� 
	//���и��������ָ�뼰����ָ���������������� 
	std::unique_ptr<Resource> ptr(new Resource());

    return 0;
}
