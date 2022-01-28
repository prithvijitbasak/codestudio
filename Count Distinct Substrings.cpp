//Editorial: https://youtu.be/RV0QeTyHZxo
struct Node{
    Node* links[26];
    bool flag=false;
    bool containskey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    Node* getnode(char ch)
    {
        return links[ch-'a'];
    }
    void putnode(char ch,Node* temp)
    {
         links[ch-'a']=temp;
    }
    void setend()
    {
        flag=true;
    }
    bool isend()
    {
        return flag;
    }
};
int countDistinctSubstrings(string &word)
{
    int cnt=0;
    Node* root=new Node();
    for(int i=0;i<word.size();i++)
    {
        Node* temp=root;
        for(int j=i;j<word.size();j++)
        {
            if(!temp->containskey(word[j]))
            {
                cnt++;
                temp->putnode(word[j],new Node());
            }
            temp=temp->getnode(word[j]);
        }
    }
    return cnt+1;
}
