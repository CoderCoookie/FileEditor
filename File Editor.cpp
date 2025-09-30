#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;

// �����ļ�
void createFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) file.close();
}

// ɾ���ļ�
void deleteFile(const string& filename) {
	remove(filename.c_str());
}

// �ж��ļ��Ƿ����
bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

// ���ļ�д������
void writeFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}

// ��ȡ�ļ�����
string readFile(const string& filename) {
    ifstream file(filename);
    stringstream buffer;
    if (file.is_open()) {
        buffer << file.rdbuf();
        file.close();
    }
    return buffer.str();
}

// �޸��ļ�����
void modifyFile(const string& filename, const string& newContent) {
    string content = readFile(filename);
    writeFile(filename, content + "\n" + newContent);
}

void tip() {
	cout << "request number: ";
	int n;
	cin >> n;
	cout << "operations: " << endl;
	cout << "create file: c\nwrite file: w\nread file: r\nmodify file: m\ndelete file: d\nfile exists: f";
	while (n--) {
		char op;
		cin >> op;
		if (op =='c') {
			string filename;
			cout << "file name: ";
			cin >> filename;
			createFile(filename);
		}
		else if (op == 'w') {
			string filename,text;
			cout << "file name: ";
			cin >> filename;
			cout << "write texts: ";
			cin >> text;
			writeFile(filename,text);
		}
		else if (op == 'r') {
			string filename;
			cout << "file name: ";
			cin >> filename;
			cout << readFile(filename);
		}
		else if (op == 'm') {
			string filename,text;
			cout << "file name: ";
			cin >> filename;
			cout << "appended texts: ";
			cin >> text;
			modifyFile(filename,text);
		}
		else if (op == 'd') {
			string filename;
			cout << "file name: ";
			cin >> filename;
			deleteFile(filename);
		}
		else if (op == 'f') {
			string filename;
			cout << "file name: ";
			cin >> filename;
			cout << fileExists(filename) << endl;
		}
	}
	return ;
}

void func() {
	int n;
	cin >> n;
	while (n--) {
		char op;
		cin >> op;
		if (op =='c') {
			string filename;
			cin >> filename;
			createFile(filename);
		}
		else if (op == 'w') {
			string filename,text;
			cin >> filename;;
			cin >> text;
			writeFile(filename,text);
		}
		else if (op == 'r') {
			string filename;
			cin >> filename;
			cout << readFile(filename);
		}
		else if (op == 'm') {
			string filename,text;
			cin >> filename;
			cin >> text;
			modifyFile(filename,text);
		}
		else if (op == 'd') {
			string filename;
			cin >> filename;
			deleteFile(filename);
		}
		else if (op == 'f') {
			string filename;
			cin >> filename;
			cout << fileExists(filename) << endl;
		}
	}
	return ;
}

int main() {
	func();
    return 0;
}
