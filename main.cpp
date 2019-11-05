int main(int argc, char const *argv[]) {
  std::chrono::system_clock::time_point start, end;
  double elapsed;
  const long int MAX = 100000;
  long int a[MAX+1];
  // Array
  start = std::chrono::system_clock::now();
  for (long int i = 0; i <= MAX; i++) {
    a[i] = i;
  }
  long int sum1 = 0;
  for (long int i = 0; i <= MAX; i++) {
    sum1 += a[i];
  }
  end = std::chrono::system_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
  std::cout << elapsed << "μs" << std::endl;
  return 0;
}