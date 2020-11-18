#include <stdio.h>

/*Colors
[0;31m	Red
[1;31m	Bold Red
[0;32m	Green
[1;32m	Bold Green
[0;33m	Yellow
[01;33m	Bold Yellow
[0;34m	Blue
[1;34m	Bold Blue
[0;35m	Magenta
[1;35m	Bold Magenta
[0;36m	Cyan
[1;36m	Bold Cyan
[0m	Reset*/

int colorRed(){
    printf("\033[0;31m");
    return 0;
}

int colorRedBold(){
    printf("\033[1;31m");
    return 0;
}

int colorGreen(){
    printf("\033[0;32m");
    return 0;
}

int colorGreenBold(){
    printf("\033[1;32m");
    return 0;
}

int colorYellow(){
    printf("\033[0;33m");
    return 0;
}

int colorYellowBold(){
    printf("\033[1;33m");
    return 0;
}

int colorBlue(){
    printf("\033[0;34m");
    return 0;
}

int colorBlueBold(){
    printf("\033[1;34m");
    return 0;
}

int colorMagenta(){
    printf("\033[0;35m");
    return 0;
}

int colorMagentaBold(){
    printf("\033[1;35m");
    return 0;
}

int colorCyan(){
    printf("\033[0;36m");
    return 0;
}

int colorCyanBold(){
    printf("\033[1;36m");
    return 0;
}

int colorReset(){
    printf("\033[0m");
    return 0;
}
