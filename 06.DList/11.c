ListNode* reverse(ListNode* head)
{
    ListNode *pnode=head,*pre=NULL;   //pnodeָ��ǰ�ڵ㣬preָ��ǰһ�ڵ�
    while (pnode)                                      //��pnode��=nullʱ����ʼ��ת
    {
        ListNode* pnext=pnode->next;   //���ȱ���pnode����һ�ڵ㱣�浽pnext������ת��1����ʱ�ᶪʧ��һ�ڵ�ָ��
        pnode->next=pre;                       //��ת��1������ָ��ǰһ�ڵ㣬��pnodeΪͷ�ڵ�ʱ��preָ��Ϊ�ա�
        pnode->pre=pnext;  //��ת��2������ָ����һ�ڵ㣬��pnodeΪβ�ڵ�ʱ��pnextָ��Ϊ�ա�
        pre=pnode;     //��ת��ɣ�����preָ�롣
        pnode=pnext;     //����pnodeָ�롣
    }
    return pre;     //��pnodeΪNullʱ��˵���Ѿ���ת��ϣ�����ǰһ�ڵ�preָ��β�ڵ㡣���ش˽ڵ�ָ�롣
}
