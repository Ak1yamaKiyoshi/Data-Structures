const buildBadMatchTable = (str) => {
    const tableObj = {}
    const strLength = str.length
    for (let i = 0; i < strLength - 1; i++) {
        tableObj[str[i]] = strLength - 1 - i
    }
    if (tableObj[str[strLength - 1]] === undefined) {
        tableObj[str[strLength - 1]] = strLength
    }
    return tableObj
}

const boyerMoore = (str, pattern) => {
    const badMatchTable = buildBadMatchTable(pattern)
    let offset = 0
    const patternLastIndex = pattern.length - 1
    const maxOffset = str.length - pattern.length
    // if the offset is bigger than maxOffset, cannot be found
    while (offset <= maxOffset) {
        let scanIndex = 0
        while (pattern[scanIndex] === str[scanIndex + offset]) {
            if (scanIndex === patternLastIndex) {
                // found at this index
                return offset
            }
            scanIndex++
        }
        const badMatchString = str[offset + patternLastIndex]
        if (badMatchTable[badMatchString]) {
            // increase the offset if it exists
            offset += badMatchTable[badMatchString]
        } else {
            offset++
        }
    }
    return -1
}


/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */

const hammingDistance = (a, b) => {
    if (a.length !== b.length) {
        throw new Error('Strings must be of the same length')
    }

    let distance = 0

    for (let i = 0; i < a.length; i += 1) {
        if (a[i] !== b[i]) {
            distance += 1
        }
    }

    return distance
}

const computeLPS = (pattern) => {
    const lps = Array(pattern.length)
    lps[0] = 0
    for (let i = 1; i < pattern.length; i++) {
        let matched = lps[i - 1]
        while (matched > 0 && pattern[i] !== pattern[matched]) {
            matched = lps[matched - 1]
        }
        if (pattern[i] === pattern[matched]) {
            matched++
        }
        lps[i] = matched
    }
    return lps
}

/**
 * Returns all indices where pattern starts in text
 * @param {*} text a big text in which pattern string is to find
 * @param {*} pattern the string to find
 */
const KMPSearch = (text, pattern) => {
    if (!pattern || !text) {
        return [] // no results
    }

    // lps[i] = length of proper prefix of pattern[0]...pattern[i-1]
    //          which is also proper suffix of it
    const lps = computeLPS(pattern)
    const result = []

    let matched = 0
    for (let i = 0; i < text.length; i++) {
        while (matched > 0 && text[i] !== pattern[matched]) {
            matched = lps[matched - 1]
        }
        if (text[i] === pattern[matched]) {
            matched++
        }
        if (matched === pattern.length) {
            result.push(i - pattern.length + 1)
            matched = lps[matched - 1]
        }
    }

    return result
}

const levenshteinDistance = (a, b) => {
    // Declaring array 'D' with rows = len(a) + 1 and columns = len(b) + 1:
    const distanceMatrix = Array(b.length + 1)
        .fill(null)
        .map(() => Array(a.length + 1).fill(null))

    // Initializing first column:
    for (let i = 0; i <= a.length; i += 1) {
        distanceMatrix[0][i] = i
    }

    // Initializing first row:
    for (let j = 0; j <= b.length; j += 1) {
        distanceMatrix[j][0] = j
    }

    for (let j = 1; j <= b.length; j += 1) {
        for (let i = 1; i <= a.length; i += 1) {
            const indicator = a[i - 1] === b[j - 1] ? 0 : 1
            // choosing the minimum of all three, vis-a-vis:
            distanceMatrix[j][i] = Math.min(
                distanceMatrix[j][i - 1] + 1, // deletion
                distanceMatrix[j - 1][i] + 1, // insertion
                distanceMatrix[j - 1][i - 1] + indicator // substitution
            )
        }
    }

    return distanceMatrix[b.length][a.length]
}



/* function that calculates hashsum of string */
function hash(str) {
    return str.split('').reduce(function (acc, l) { return acc + l.charCodeAt(0); }, 0);
}

/* function to normalize text */
function normalize(str) {
    return str.toUpperCase().replace(/\s/g, '')
        .replace(/[^a-zA-Z0-9u0400-\u04FF0-9]/g, '');
}


/* function to compare two hashsums */
function compareHash(hash1, hash2, multiplier) {
    console.log(hash1, hash2 + ((toString(hash2).length - 1) * multiplier), hash2 - ((toString(hash2).length - 1) * multiplier))
    return (hash1 < hash2 + ((toString(hash2).length - 1) * multiplier) && hash1 > hash2 - ((toString(hash2).length - 1) * multiplier))
}


/* function that makes sets from two strings */
function makeSet(str) {
    let set = new Set();
    for (let i = 0; i < str.length; i++) { set.add(str[i]); }
    return set;
}


/* function that returns value that has first set, but not second set */
function differenceFirstFromSecondSet(set1, set2) {
    let difference = new Set();
    for (let elem of set1) {
        if (!set2.has(elem)) { difference.add(elem); }
    }
    return difference;
}


/* function that checks if there words in string */
function checkIfThereIsWordsInString(str, minimumWords) {
    return (str.split(' ').length > minimumWords)
}


/* function that returns sorted array with strings that occurs in string multiple times */
function mostOccuredWords(string, minCharachtersInWord, limit) {
    string = string.replace(/[^ a-zA-Z0-9u0400-\u04FF0-9]/g, '');
    array = [];
    new Set(string.split(' ')).forEach(word => {
        if (word != '' && word.length >= minCharachtersInWord)
            array.push({ word: word, occurence: string.split(word).length - 1 });
    });
    array.sort(function (a, b) { return b.occurence - a.occurence; });;
    return array.slice(0, limit);
}


let text = 'Турция в конце прошлого года передала Украине кассетные артиллерийские боеприпасы. Об этом сообщил американский журнал Foreign Policy (FP) со ссылкой на американских и европейских официальных лиц. По данным издания, ранее Киев безуспешно пытался добиться таких поставок от США.Речь идёт об усовершенствованных обычных боеприпасах двойного назначения (Dual-Purpose Improved Conventional Munitions, DPICM), которые были произведены в Турции по соглашению с Соединёнными Штатами во времена холодной войны, пишет издание. Они предназначены для уничтожения бронетехники — при выстреле каждый из них разлетается на 88 более мелких боеприпасов.Кассетное оружие запрещено международной конвенцией, принятой в 2010 году, однако Украина, Турция, США и Россия к ней не присоединились. Не в числе государств — участников соглашения и Казахстан.По информации источников издания, Анкара в течение нескольких месяцев пыталась скрыть передачу кассетных боеприпасов Киеву. После того как США отказали Украине в доступе к ним, Турция стала единственным местом, где Киев мог их получить. Американские законы запрещают экспорт DPICM — из-за высокой доли неразорвавшихся боеприпасов, которые ещё многие годы могут представлять опасность для мирного населения.Журналисты сообщают, что отправка боеприпасов началась в ноябре, однако пока не ясно, применяются ли они уже на поле боя.«Это показывает, что Турция хоть и пытается в некоторых отношениях угодить России, но предоставляет Украине очень важную военную поддержку», — сказал изданию один из источников.Турецкое посольство в Вашингтоне и министерство обороны Украины не ответили на просьбы Foreign Policy прокомментировать данные о поставках кассетных боеприпасов.Как пишут турецкие СМИ, чиновники в Анкаре с заявлениями не выступили. Киев также не отреагировал на информацию.'
let string = 'Турція поставляет, Украине кабоеприпасы — Foreign Policy'

mostOccuredWords(text, 4, 3).forEach(word => {
    console.log(word.word, word.occurence)
});
console.log((new Set(string.split(' '))))