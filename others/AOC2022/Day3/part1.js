
const dataUrl = "https://adventofcode.com/2022/day/3/input"
const ansUrl = "https://adventofcode.com/2022/day/3/answer"
const cookie = "paste your cookie here"

const request = new Request(dataUrl, {
    method: 'GET',
    headers: {
        cookie: cookie,
    },
})

fetch(request)
    .then(res => res.text())
    .then(data => {
        // console.log(typeof data);
        const arr = data.split('\n')
        // console.log(arr.length);
        let cnt = 0;
        arr.forEach((str) => {
            let set = new Set();
            for (let i = 0; i < str.length / 2; ++i) {
                set.add(str[i]);
            }
            for (let i = str.length / 2; i < str.length; ++i) {
                if (set.has(str[i])) {
                    if (/[A-Z]/.test(str[i])) {
                        cnt += str[i].charCodeAt() - 'A'.charCodeAt() + 27;
                    } else {
                        cnt += str[i].charCodeAt() - 'a'.charCodeAt() + 1;
                    }
                    break;
                }
            }
        })
        console.log("The answer is", cnt);
        return cnt;
    }).then(result => {
        let formData = new FormData();
        formData.append("level", 1);
        formData.append("answer", result);
        // console.log(formData);
        fetch(ansUrl, {
            method: "POST",
            headers: {
                cookie: cookie,
            },
            body: formData,
        }).then(res => {
            console.log(res.headers.get("content-length"));
            // return res.text();
        })
        // .then(data => console.log(data))

    })



