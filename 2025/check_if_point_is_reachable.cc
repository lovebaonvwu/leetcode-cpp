class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        if (targetX == 1 && targetY == 1) {
            return true;
        } else if (targetX % 2 == 0) {
            return isReachable(targetX / 2, targetY);
        } else if (targetY % 2 == 0) {
            return isReachable(targetX, targetY / 2);
        } else if (targetX > targetY) {
            return isReachable(targetX - targetY, targetY);
        } else if (targetX < targetY) {
            return isReachable(targetX , targetY - targetX);
        }
    
        return false;
    }
};
// 0 ms
// 7.73 MB
