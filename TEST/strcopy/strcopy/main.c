//
//  main.c
//  strcopy
//
//  Created by 程锋 on 15/8/19.
//  Copyright (c) 2015年 程锋. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    char from[100] = "123456789E";
    
    strcpy(from+2, from);
    
    printf("%s\n", from);
    
    
    return 0;
}
