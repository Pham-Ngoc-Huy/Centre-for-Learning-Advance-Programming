// file 1.cpp
// We gonna have 2 files 
// 1. file_1.cpp --> which contain variable 
// 2. Topic.cpp

int a = 10; // glocval, var --> linkage: ready to be linked
void add(const int& a, const int& b, int& c){
    c = a + b;
}
extern const double pi = 3.145678929; // global, const --> Not ready to be linked --> we can change the properties of linkage property by use extern