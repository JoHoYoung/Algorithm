function solution(food_times, k) {
    let data = [];
    let GG = 0;
    for (let i = 0; i < food_times.length; i++) {
        GG += food_times[i];
        data[i] = {idx: i, val: food_times[i]};
    }

    if (GG <= k)
        return -1;

    data.sort((a, b) => {
        return a.val - b.val;
    });

    let sum = 0;
    let idx = 0;
    let remainder;

    if (sum + data[idx].val * (data.length - idx) < k) {
        sum += data[idx].val * (data.length - idx);
        idx++;
        let temp;
        for (idx; idx < data.length; idx++) {
            temp = sum + (data[idx].val - data[idx - 1].val) * (data.length - idx);
            if (temp >= k) {
                break;
            }
            sum = temp;
        }
    }

    remainder = k - sum;
    let numberOfDishes = data.length - idx;
    let temp = Math.floor(remainder / numberOfDishes);
    let last = remainder % numberOfDishes;
    let pivot = idx === 0 ? temp : data[idx - 1].val + temp;
    data = data.filter(el => el.val > pivot);

    data.sort((a, b) => {
        return a.idx - b.idx;
    });
    return data[last].idx + 1;
}
