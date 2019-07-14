// k초엔 몇번째 음식을 먹는가?

function solution(food_times, k) {
    k++;
    let foodIdx = 0;
    let kIdx = 0;
    let now = 0;
    while (1) {
        if (now === food_times.length ) {
            return -1;
        }

        if (foodIdx === food_times.length) {
            foodIdx = 0;
            continue;
        }
        if (food_times[foodIdx] === 0) {
            now++;
            foodIdx++;
            continue;
        }
        now = 0;
        food_times[foodIdx++]--;
        kIdx++;

        if (kIdx === k) {
            return foodIdx;
        }
    }
}
