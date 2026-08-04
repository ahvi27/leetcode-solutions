var maxProduct = function(nums) {
    let maxProduct = nums[0];
    let minProduct = nums[0];
    let result = nums[0];

    for (let i = 1; i < nums.length; i++) {
        let num = nums[i];

        // Save previous values before updating
        let tempMax = maxProduct;
        let tempMin = minProduct;

        maxProduct = Math.max(
            num,
            tempMax * num,
            tempMin * num
        );

        minProduct = Math.min(
            num,
            tempMax * num,
            tempMin * num
        );

        result = Math.max(result, maxProduct);
    }

    return result;
};