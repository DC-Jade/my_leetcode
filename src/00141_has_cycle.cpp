#include <cstdlib>
#include <vector>
#include <ctime>

using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool HasCycle(LisNode *head);

/* fast - step = 2 slow - step = 1 */
void SolutionOne(ListNode *head) {
	/* case - 0 or 1 node */
	if (head == nullptr || head->next == nullptr) return false;
	ListNode *slow = head;
	ListNode *fast = head->next;
	while (slow != fast) {
		if (fast == nullptr || fast->net == nullptr) { return false; }
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}

void Solution(ListNode *head) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1:
			printf("SolutionOne:\n");
			SolutionOne(head);
			break;
	}
}

void Test00141() {
	Solution(head);
}

int main(int argc, char **argv) {
	Test00141();
}
