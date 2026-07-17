class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());

        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        // Triangle condition
        if (a + b <= c) return {};

        // Cosine rule
        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));

        // Convert to degrees
        A = A * 180.0 / M_PI;
        B = B * 180.0 / M_PI;
        C = C * 180.0 / M_PI;

        vector<double> angles = {A, B, C};
        sort(angles.begin(), angles.end());

        return angles;
    }

};