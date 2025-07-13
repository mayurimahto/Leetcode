//1423. Maximum Points You Can Obtain from Cards

class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int leftSum=0;
        int rightSum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        maxSum=leftSum;
        int right=cardPoints.length-1;
        for(int left=k-1;left>=0;left--){
            leftSum-=cardPoints[left];
            rightSum+=cardPoints[right];
            right--;
            maxSum=Math.max(maxSum, leftSum+rightSum);
        }
        return maxSum;
    }
}
