 int trap(vector<int>& height) {
        int sum = 0, h = 0, max_idx = 0, max_val = 0;

    for(int i=0; i < height.size(); i++) {
        if (height[i] >= max_val) {
            max_val = height[i];
            max_idx = i;
        }
    }
    
    for(int i=0; i < max_idx; i++) {
        if (height[i] < h) {
            sum += h - height[i];
          } else {
            h = height[i];
        }
    }
    h = 0;
    for(int i=height.size()-1; i >= max_idx; i--) {
        if (height[i] < h) {
            sum += h - height[i];
        } else {
            h = height[i];
        }
    }
    return sum;
    }