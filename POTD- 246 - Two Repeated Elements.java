 //Function to find two repeated elements.
    public int[] twoRepeated(int arr[], int n)
    {
        // Your code here
       int[] res = new int[2];
        ArrayList<Integer> temp = new ArrayList<>();
        
        for (int i = 0; i < n + 2; i++) {
            if (arr[Math.abs(arr[i]) - 1] > 0) {
                arr[Math.abs(arr[i]) - 1] = -arr[Math.abs(arr[i]) - 1];
            } else {
                temp.add(Math.abs(arr[i]));
            }
            if (temp.size() == 2) {
                res[0] = temp.get(0);
                res[1] = temp.get(1);
                break;
            }
        }
        return res;
    }
