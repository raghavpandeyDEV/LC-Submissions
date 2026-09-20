class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int rcmax = xCenter + radius;
        int lcmax = xCenter - radius;
        int tcmax = yCenter + radius;
        int bcmax = yCenter - radius;

        int lmax = x1;
        int rmax = x2;
        int topmax = y2;
        int bmax = y1;

        // Center is horizontally/vertically aligned with rectangle
        if (xCenter >= lmax && xCenter <= rmax &&
            yCenter >= bmax && yCenter <= topmax)
            return true;

        // Find closest x
        int closestX = xCenter;

        if (xCenter < lmax)
            closestX = lmax;
        else if (xCenter > rmax)
            closestX = rmax;

        // Find closest y
        int closestY = yCenter;

        if (yCenter < bmax)
            closestY = bmax;
        else if (yCenter > topmax)
            closestY = topmax;

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        if (dx * dx + dy * dy <= radius * radius)
            return true;

        return false;
    }
};