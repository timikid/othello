#define N 6

void init(int a[][N]);
void print_othello(int a[][N]);
void status(int a[][N]);

int put_w(int a[][N]);
int put_b(int a[][N]);

int over_w(int a[][N]);
int over_b(int a[][N]);

void flip_result_w();
void flip_result_b();
void init_flip();

void game_over(int a[][N]);
