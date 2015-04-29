/**
 * Assorted utility functions.
 */

///////////////////////////////////////////////////////////////////////////
// constants

// Unicode CJK Unified Ideographs
 MIN_UVALUE = 0x4E00;
 MAX_UVALUE = 0x9FA5;

// The range of Big5a
 MIN_BIG5A = 0xA440;
 MAX_BIG5A = 0xC69F;

// Return the URL base of this file
 getUrlBase = function() {
    var scripts = document.getElementsByTagName("script");
    for (var i in scripts) {
        var src = scripts[i].src;
        if (src && src.endsWith("/ js")) {
            var left = src.split("?")[0];
            var url = left.substr(0, left.lastIndexOf("/"));
            url = url.substr(0, url.lastIndexOf("/"));
            return url;
        }
    }

    // weird
    return "";
};

///////////////////////////////////////////////////////////////////////////
// range checking

// Returns true if the first character is Chinese
 isChinese = function(ch) {
    if (!ch || ch.length === 0) {
        return false;
    }

    var i = ch.charCodeAt(0);
    return i >=  MIN_UVALUE && i <=  MAX_UVALUE;
};

// Returns true if the Big5 character code (as a string) is Big5a
 isBig5a = function(value) {
    if (!value) {
        return false;
    }

    value = parseInt(value, 16);
    return value >=  MIN_BIG5A && value <=  MAX_BIG5A;
};

///////////////////////////////////////////////////////////////////////////
// functions

// Return a new string by replacing one character with supplied string
 setCharAt = function(str, i, ch) {
    if (i < str.length) {
        return str.substr(0, i) + ch + str.substr(i + 1);
    }

    return str;
};

// Given a string that contains 0 or more U+ values, return
// an array of 0 or more corresponding Unicode characters
 convertCode = function(value) {
    if (!value) {
        return [];
    }

    var splits = value.split("U+");
    if (splits.length < 2) {
        return [];
    }

    var result = [];
    splits = splits.slice(1);

    for (var i in splits) {
        result.push(String.fromCharCode(parseInt(splits[i], 16)));
    }

    return result;
};

// Given a string that contains 0 or more radical.stroke counts,
// return an array of 0 or more {"R":int, "S":int} values.
 parseRS = function(value) {
    if (!value) {
        return [];
    }

    var results = [];
    var splits = value.split(" ");

    for (var i in splits) {
        var str = splits[i];
        var iS = str.lastIndexOf(".");
        if (iS > 0) {
            var r = parseInt(str, 10);
            if (r) {
                var s = parseInt(str.substr(iS + 1), 10);
                results.push({"R":r, "S":s});
            }
        }
    }

    return results;
};

// Compares two RS strings.
 compareRS = function(a, b) {
    var rs1 =  parseRS(a);
    var rs2 =  parseRS(b);
    if (rs1.length > 0 && rs2.length > 0) {
        return rs1[0].R === rs2[0].R && rs1[0].S === rs2[0].S;
    }

    return false;
};

// Find U+xxxx sequences and insert parenthetical Unicode characters
 injectUnicode = function(value) {
    if (value === null) {
        return "";
    }

    var splits = value.split("U+");
    if (splits.length == 1) {
        return value;
    }

    var result = splits[0];
    splits = splits.slice(1);

    for (var s in splits) {
        var splits2 = splits[s].split(" ");
        var v = splits2[0];
        var x = "";
        if (splits2.length > 1) {
            x = " " + splits2.slice(1).join(" ");
        }

        result += "U+" + v + " (" + String.fromCharCode(parseInt(v, 16)) + ")" + x;
    }

    return result;
};

///////////////////////////////////////////////////////////////////////////
// sounds

// Split the given sound and its tone, if any
 splitSound = function(value) {
    var result = "";
    if (value) {
        result = value.toLowerCase();
    }

    var tone = parseInt(value.substr(value.length - 1), 10);
    if (isNaN(tone)) {
        tone = 0;
    } else {
        result = result.substr(0, result.length - 1);
    }

    var iV = result.indexOf("v");
    if (iV >= 0) {
        result =  setCharAt(result, iV, "\u00FC");
    }

    return [result, tone];
};

 addDiacritic = function(value, tone) {
    if (value === "ng") {
        switch (tone) {
        case 2: value =  setCharAt(value, 0, "\u0144"); break;
        case 3: value =  setCharAt(value, 0, "\u0148"); break;
        case 4: value += "\u0300"; break;
        }

        return value;
    }

    if (value === "m") {
        switch (tone) {
        case 2: value += "\u0301"; break;
        case 4: value += "\u0300"; break;
        }

        return value;
    }

    var iA = value.lastIndexOf("a");  // for Yale
    var iO = value.indexOf("o");
    var iE = value.indexOf("e");
    var iI = value.indexOf("i");
    var iU = value.indexOf("u");
    var iV = value.indexOf("\u00FC");

    var iIU = value.indexOf("iu");
    if (iIU >= 0) {
        iI = -1;
        iU = iIU + 1;
    }

    if (iA >= 0) {
        switch (tone) {
        case 1: value =  setCharAt(value, iA, "\u0101"); break;
        case 2: value =  setCharAt(value, iA, "\u00E1"); break;
        case 3: value =  setCharAt(value, iA, "\u01CE"); break;
        case 4: value =  setCharAt(value, iA, "\u00E0"); break;
        }
    }
    else if (iO >= 0) {
        switch (tone) {
        case 1: value =  setCharAt(value, iO, "\u014D"); break;
        case 2: value =  setCharAt(value, iO, "\u00F3"); break;
        case 3: value =  setCharAt(value, iO, "\u01D2"); break;
        case 4: value =  setCharAt(value, iO, "\u00F2"); break;
        }
    }
    else if (iE >= 0) {
        switch (tone) {
        case 1: value =  setCharAt(value, iE, "\u0113"); break;
        case 2: value =  setCharAt(value, iE, "\u00E9"); break;
        case 3: value =  setCharAt(value, iE, "\u011B"); break;
        case 4: value =  setCharAt(value, iE, "\u00E8"); break;
        }
    }
    else if (iI >= 0) {
        switch (tone) {
        case 1: value =  setCharAt(value, iI, "\u012B"); break;
        case 2: value =  setCharAt(value, iI, "\u00ED"); break;
        case 3: value =  setCharAt(value, iI, "\u01D0"); break;
        case 4: value =  setCharAt(value, iI, "\u00EC"); break;
        }
    }
    else if (iU >= 0) {
        switch (tone) {
        case 1: value =  setCharAt(value, iU, "\u016B"); break;
        case 2: value =  setCharAt(value, iU, "\u00FA"); break;
        case 3: value =  setCharAt(value, iU, "\u01D4"); break;
        case 4: value =  setCharAt(value, iU, "\u00F9"); break;
        }
    }
    else if (iV >= 0) {
        switch (tone) {
        case 1: value =  setCharAt(value, iV, "\u01D6"); break;
        case 2: value =  setCharAt(value, iV, "\u01D8"); break;
        case 3: value =  setCharAt(value, iV, "\u01DA"); break;
        case 4: value =  setCharAt(value, iV, "\u01DC"); break;
        }
    }

    return value;
};

///////////////////////////////////////////////////////////////////////////
// pinyin

// Convert a list of space-separated Unihan-format sounds to an array of pinyin syllables
 getSoundsPinyin = function(value) {
    var results = [];
    if (!value) {
        return results;
    }

    var splits = value.split(" ");
    for (var i in splits) {
        results.push( convertPinyin(splits[i]));
    }

    return results;
};

// Convert a list of space-separated Unihan-format sounds to pinyin
 convertSoundsPinyin = function(value) {
    return  getSoundsPinyin(value).join(" ");
};

// Convert from Unihan format (upper-case, with tone numbers) to real pinyin.
 convertPinyin = function(value) {
    var split =  splitSound(value);
    var result = split[0];
    var tone = split[1];
    if (tone < 1 || tone > 5) {
        return result;
    }

    return  addDiacritic(result, tone);
};

///////////////////////////////////////////////////////////////////////////
// Yale romanization for Cantonese

// Convert a list of space-separated Unihan-format sounds to an array of Yale syllables
 getSoundsYale = function(value) {
    var results = [];
    if (!value) {
        return results;
    }

    var splits = value.split(" ");
    for (var i in splits) {
        results.push( convertYale(splits[i]));
    }

    return results;
};

// Convert a list of space-separated Unihan-format sounds to Yale
 convertSoundsYale = function(value) {
    return  getSoundsYale(value).join(" ");
};

// Convert from Unihan format (with tone numbers) to real Yale.
 convertYale = function(value) {
    var split =  splitSound(value);
    var result = split[0];
    var tone = split[1];
    if (tone < 1 || tone > 6) {
        return result;
    }

    if (tone >= 4) {
        result += "h";
    }

    if (tone === 3 || tone === 6) {
        return result;
    }

    if (tone === 5) {
        tone = 2;
    }

    return  addDiacritic(result, tone);
};

///////////////////////////////////////////////////////////////////////////
// filters

// Negate things like x, x+y, x|y
 invertFilter = function(term) {
    var result = "";
    if (!term) {
        return result;
    }

    var sep = null;
    if (term.indexOf("+") > 0) {
        sep = "+";
    }

    if (term.indexOf("|") > 0) {
        if (sep) {
            return result;
        }

        sep = "|";
    }

    function invertOne(one) {
        if (one.charAt(0) === "!") {
            return one.substr(1);
        }

        return "!" + one;
    }

    if (!sep) {
        return invertOne(term.trim());
    }

    var fields = term.split(sep);
    sep = (sep === "+") ? "|" : "+";

    for (var i = 0; i < fields.length; i++) {
        if (i > 0) {
            result += sep;
        }

        result += invertOne(fields[i].trim());
    }

    return result;
};

// Multiply out Boolean AND filter. Examples:
//    a+b AND c+d = a+b+c+d
//    a+b AND c|d = a+b+c|a+b+d
//    a|b AND c|d = a+c|a+d|b+c|b+d
 andFilters = function(x, y) {
    var result = "";
    if (!x | !y) {
        return result;
    }

    var f1 = x.split("|");
    var f2 = y.split("|");

    for (var i = 0; i < f1.length; i++) {
        for (var j = 0; j < f2.length; j++) {
            if (result.length > 0) {
                result += "|";
            }

            result += f1[i] + "+" + f2[j];
        }
    }

    return result;
};

///////////////////////////////////////////////////////////////////////////////
// unit testing

 check = function(input, expected, result) {
    if (expected instanceof Array) {
        expected = JSON.stringify(expected);
    }

    if (result instanceof Array) {
        result = JSON.stringify(result);
    }

    if (expected != result) {
        console.log("Fail: \"" + input + "\" = \"" + result + "\"");
        console.log("Expected: \"" + expected + "\"");
    }
};

 testAll = function() {
    var s = "U+4E00";
    var e = ["\u4e00"];
     check(s, e,  convertCode(s));

    s = " xxx U+5E00 xxx U+6E00 xxx ";
    e = ["\u5E00", "\u6E00"];
     check(s, e,  convertCode(s));

    s = " blah ";
    e = [];
     check(s, e,  convertCode(s));

    s = "162.1 163'.2";
    e = [{R:162, S:1}, {R:163, S:2}];
     check(s, e,  parseRS(s));

    s = " blah.2 162 163xxx.2  1..2";
    e = [{R:163, S:2}, {R:1, S:2}];
     check(s, e,  parseRS(s));

    s = " blah ";
    e = [];
     check(s, e,  parseRS(s));

    s = "FAN1 FAN2 FAN3 FAN4 FAN5";
    e = "fÄn fÃ¡n fÇŽn fÃ n fan";
     check(s, e,  convertSoundsPinyin(s));

    s = "a ai an ang ao";
    e = "a ai an ang ao";
     check(s, e,  convertSoundsPinyin(s));

    s = "CHENG1 CHENG2 CHENG3 CHENG4 CHENG5";
    e = "chÄ“ng chÃ©ng chÄ›ng chÃ¨ng cheng";
     check(s, e,  convertSoundsPinyin(s));

    s = "CHIU1 CHIU2 CHIU3 CHIU4 CHIU5";
    e = "chiÅ« chiÃº chiÇ” chiÃ¹ chiu";
     check(s, e,  convertSoundsPinyin(s));

    s = "lv1 lv2 lv3 lv4 lv5";
    e = "lÇ– lÇ˜ lÇš lÇœ lÃ¼";
     check(s, e,  convertSoundsPinyin(s));

    s = "lÃ¼1 lÃ¼2 lÃ¼3 lÃ¼4 lÃ¼5";
    e = "lÇ– lÇ˜ lÇš lÇœ lÃ¼";
     check(s, e,  convertSoundsPinyin(s));

    s = "ng2 ng3 ng4";
    e = "Å„g Åˆg ngÌ€";
     check(s, e,  convertSoundsPinyin(s));

    s = "m2 m3 m4";
    e = "mÌ m mÌ€";
     check(s, e,  convertSoundsPinyin(s));

    s = "ping51";
    e = "pÄ«ng5";
     check(s, e,  convertSoundsPinyin(s));

    s = "ping51";
    e = "pingx1";
     check(s, e,  setCharAt(s, 4, "x"));

    e = "ping5x";
     check(s, e,  setCharAt(s, 5, "x"));

    e = s;
     check(s, e,  setCharAt(s, 6, "x"));

    s = "U+4E00";
    e = "U+4E00 (\u4E00)";
     check(s, e,  injectUnicode(s));

    s = "U+4E00 U+4E10";
    e = "U+4E00 (\u4E00) U+4E10 (\u4E10)";
     check(s, e,  injectUnicode(s));

    s = "hello U+4E00 world U+4E10 hello";
    e = "hello U+4E00 (\u4E00) world U+4E10 (\u4E10) hello";
     check(s, e,  injectUnicode(s));

    s = " hello U+4E00 world U+4E10 hello ";
    e = " hello U+4E00 (\u4E00) world U+4E10 (\u4E10) hello ";
     check(s, e,  injectUnicode(s));

    s = "\u4e00";
     check(s, true,  isChinese(s));

    s = "\u5e00";
     check(s, true,  isChinese(s));

    s = "\u9fA5";
     check(s, true,  isChinese(s));

    s = "\u4dff";
     check(s, false,  isChinese(s));

    s = "\u9fa6";
     check(s, false,  isChinese(s));

    s = "";
     check(s, false,  isChinese(s));

    s = "a";
     check(s, false,  isChinese(s));

    s = "A440";
     check(s, true,  isBig5a(s));

    s = "a440";
     check(s, true,  isBig5a(s));

    s = "BDDD";
     check(s, true,  isBig5a(s));

    s = "a43f";
     check(s, false,  isBig5a(s));

    s = "x";
    e = "!x";
     check(s, e,  invertFilter(s));

    s = "x+y";
    e = "!x|!y";
     check(s, e,  invertFilter(s));

    s = "x+y+z";
    e = "!x|!y|!z";
     check(s, e,  invertFilter(s));

    s = " x + y + z ";
    e = "!x|!y|!z";
     check(s, e,  invertFilter(s));

    s = "x|y";
    e = "!x+!y";
     check(s, e,  invertFilter(s));

    s = "!x+y";
    e = "x|!y";
     check(s, e,  invertFilter(s));

    s = "!x+!y";
    e = "x|y";
     check(s, e,  invertFilter(s));

    s = "x+y|z";
    e = "";
     check(s, e,  invertFilter(s));

    var s1 = "a+b";
    var s2 = "c+d";
    e = "a+b+c+d";
     check([s1, s2], e,  andFilters(s1, s2));

    s1 = "a+b";
    s2 = "c|d";
    e = "a+b+c|a+b+d";
     check([s1, s2], e,  andFilters(s1, s2));

    s1 = "a";
    s2 = "b";
    e = "a+b";
     check([s1, s2], e,  andFilters(s1, s2));

    s1 = "a|b";
    s2 = "c+d";
    e = "a+c+d|b+c+d";
     check([s1, s2], e,  andFilters(s1, s2));

    s1 = "a|b";
    s2 = "c|d";
    e = "a+c|a+d|b+c|b+d";
     check([s1, s2], e,  andFilters(s1, s2));
};

// testAll();
