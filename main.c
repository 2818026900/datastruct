#include "ctype.h"
#include "tools/Tools.h"
#include "menu/Menu.h"
#include "linerList/LinerList.h"


int main() {
    int key,Skey;
    m: mainMenu();
    fflush(stdout); //clion中 printf 与 scanf  使用需要先使用当前语句刷新输出缓存区进行输出
    while (1)
    {
        printf("请输入菜单序号\n");
        fflush(stdout);
        scanf("%d",&key);
        fflush(stdin);//清除scanf()缓存区缓存
        if(isdigit(key)!=0)
        {
            printf("请输入正确的数字菜单序号！\n");
        }
        else
        {
            switch (key) {
                case 1:
                {
                    lineListMenu();
                    fflush(stdout);
                    while (1)
                    {
                        printf("请输入菜单序号\n");
                        fflush(stdout);
                        scanf("%d",&Skey);
                        fflush(stdin);
                        if(isdigit(Skey)!=0)
                        {
                            printf("请输入正确的数字菜单序号！\n");
                        }
                        else
                        {
                            switch (Skey) {
                                case 0:
                                {
                                    key = 'a';//key初始化
                                    goto m;//回到主菜单
                                }
                                case 1:
                                {
                                    char *string = readFile("../linerList/Introduction.txt");
                                    if (string)
                                    {
                                        puts(string);
                                        free(string);
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    printf("静态顺序表\n");
                                    fflush(stdout);
                                    int i = seq_main();
                                    printf("\n动态顺序表\n");
                                    fflush(stdout);
                                    int j = sq_main();
                                    if(i==1&&j==2)
                                        break;
                                }
                                case 3:
                                {
                                    printf("线性链表\n");
                                    fflush(stdout);
                                    break;
                                }
                                case 4:
                                {
                                    printf("循环链表\n");
                                    fflush(stdout);
                                    break;
                                }
                                case 5:
                                {
                                    printf("双向链表\n");
                                    fflush(stdout);
                                    break;
                                }
                                case 6:
                                {
                                    printf("静态链表\n");
                                    fflush(stdout);
                                    break;
                                }
                                default:
                                {
                                    printf("您的输入有误,请重新输入!!\n");
                                    fflush(stdout);
                                    break;
                                }
                            }
                            Skey = 'a';//将Skey初始化
                        }
                    };
                    break;
                }
                case 2:
                {
                    printf("栈和队列\n");
                    fflush(stdout);
                    break;
                }
                case 0:
                {
                    printf("系统已退出\n");
                    fflush(stdout);
                    return 0;
                }
                default:
                {
                    printf("您的输入有误,请重新输入!!\n");
                    fflush(stdout);
                    break;
                }
            }
            key = 'a';//key初始化
        }
    }
    return 0;
}
