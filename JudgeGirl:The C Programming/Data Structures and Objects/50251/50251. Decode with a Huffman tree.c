#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanDecoding.h"
#define MaxL 100

int is_leaf(Node* root){
    return (root -> left == NULL) && (root -> right == NULL);
}
void HuffmanDecoding(Node *root, char *data){
    char ans[100][6];
    int own = 0;
    int len = strlen(data);
    Node* node = root;
    for(int i = 0;i < len;i++){
        if(data[i] - '0') node = node -> right;
        else node = node -> left;
        int check = is_leaf(node);
        if(check){
            int lenlen = strlen(node -> symbol);
            for(int j = 0;j < lenlen;j++){
                ans[own][j] = node -> symbol[j];
                ans[own][j + 1] = 0; 
            }
            own++;
            node = root;
        }
    }
    if(node != root){
        printf("-1");
        return;
    }
    #ifdef SPACE
    for(int i = 0;i < own;i++){
        printf("%s ", ans[i]);
    }
    #endif
    #ifdef NEWLINE
    for(int i = 0;i < own;i++){
        printf("%s\n", ans[i]);
    }
    #endif
}

Node* newNode(char *symbol, int frequency, Node* l, Node* r){
    Node* new = (Node*)malloc(sizeof(Node));
    if(*symbol != '\0')
        strcpy(new->symbol,symbol);
    new->frequency = frequency;
    new->left = l, new->right = r;
    return new;
}
 
int main (){
    // sample Huffman tree  
    Node *root = newNode("\0",31,
                            newNode("\0",18,
                                    newNode("dad",10,NULL,NULL),
                                    newNode("\0",8,
                                            newNode("cat",5,NULL,NULL),
                                            newNode("\0",3,
                                                    newNode("bee",2,NULL,NULL),
                                                    newNode("ant",1,NULL,NULL)
                                                    )
                                            ) 
                                    ),
                            newNode("\0",13,
                                    newNode("fat",7,NULL,NULL),
                                    newNode("end",6,NULL,NULL)
                                    )
                        );
    // sample encoded data
    char data[MaxL];
    while(scanf("%s", data)!=EOF){
        HuffmanDecoding(root, data);
        printf("\n");
    }
    return 0;
}