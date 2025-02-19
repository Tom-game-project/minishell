#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *dir;
    struct dirent *dp;

    dir = opendir("./");

    if (dir == NULL) {
        printf("ディレクトリが開けませんでした。\n");
        return 1;
    }

    while ((dp = readdir(dir)) != NULL) {
        printf("%s\n", dp->d_name);
    }

    closedir(dir);

    return 0;
}
