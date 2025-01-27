//
// Created by marka on 12/29/2024.
//

#include "postsSearch.h"
#include "UsersBST.h"

bool cmp(post&a ,post&b) {
    return a.number_of_followers>b.number_of_followers;
}
void dfsTraverse(UserBSTNode* x ,vector <User*> &vc  ){
    if (x==NULL) return ;
    vc.push_back(x->user);
    if (x->left!=NULL){
        dfsTraverse(x->left,vc);
    }
    if (x->right!=NULL){
        dfsTraverse(x->right,vc);
    }
}
postsSearch::postsSearch (UsersGraph* t) {
    vector <User*> vc ;
    dfsTraverse(t->getUsers().getRoot(), vc);
    Hasher tmp; 
    for (auto &i : vc ){
        for (auto &j: i->getPostsList()){
            post x = post(j.topics,j.content,i->getID());
            x.number_of_followers = i->getNumOfFollowers();
            listOfPosts.push_back(x);
            for (auto &iii: j.topics){
                tmp.buildHash(iii); 
                mapOfPosts[tmp.getHashVal()].push_back(x);
            }
        }
    }
    sort (listOfPosts.begin(),listOfPosts.end(),cmp);
}

vector <post> postsSearch::searchByWord (string ser){
    
    int sz = ser.size();
    Hasher tmpword;
    tmpword.buildHash(ser); 
    auto cmp = tmpword.getHashVal();
    vector < post > ret ;
    for (auto &p: listOfPosts) {
        for (int i = 0; i + sz - 1 < min((int) p.content.size(), (int) 1e5); ++i) {
            if (p.hashedContent.getRangeHashVal(i, i + sz - 1) == cmp) {// getHash O(1)
                ret.push_back(p);
            }
        }
    }
    return ret ;
    
}
vector <post>  postsSearch::searchByTopic (string ser){
    Hasher tmpword;
    tmpword.buildHash(ser);
    auto cmp = tmpword.getHashVal();
    return mapOfPosts[cmp];
    
 
}