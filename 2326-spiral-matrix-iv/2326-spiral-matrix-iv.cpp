/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int> (n,-1));
        
        int top = 0, bot = m-1, left=0, right=n-1;
        while(head!=NULL && top<=bot && left<= right){
            for(int i=left;i<=right && head;i++){
                mat[top][i] = head->val;
                head=head->next;
            }
            top++;
            for(int j=top;j<=bot&&head ; j++){
                 mat[j][right] = head->val;
                head=head->next;
            }
            right--;
            if(top<=bot){
                for(int i = right;i>=left && head;i--){
                    mat[bot][i] = head->val;
                head=head->next;
                }
            }
            bot--;
            if(head== NULL) break;
            if(left<=right){
                for(int i = bot;i>=top && head!=NULL;i--){
                    mat[i][left] = head->val;
                head=head->next;
                }
            }
            left++;
        }
        return mat;
    }
};