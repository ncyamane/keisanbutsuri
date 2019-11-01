
// Function to show an array
void array2D(const std::vector<std::vector<size_t>>& array_2d) {
for (size_t i = 0; i < array_2d.size(); ++i) {
    for (size_t j = 0; j < array_2d[i].size(); ++j) {
        //配列の中身を出力
        std::cout << array_2d[i][j] << ',';
    }
    //改行
    std::cout << std::endl;
    }
}

int main(){

    // Declaration of 2-dim array
    std::vector<std::vector<size_t>> a(3, std::vector<size_t>(3, 1.0));
    std::vector<std::vector<size_t>> aa(3, std::vector<size_t>(3));
    std::vector<std::vector<size_t>> m(3, std::vector<size_t>(3));

    for (size_t i = 0; i < array_2d.size(); ++i) {
        for (size_t j = 0; j < array_2d[i].size(); ++j) {
        
        m[]
    }
    // show an array
    array2D(a);

    return 0;

}