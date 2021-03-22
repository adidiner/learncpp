int read_number();
void write_answer(int answer);

int main() {
    int x { read_number() };
    int y { read_number() };
    write_answer(x + y);
    return 0;
}
