function Submit() {
    //create resume object
    var res = new Resume();
    //pass resume into all functions getting form data section by section
    GetName(res);
    GetAddress(res);
    GetPhone(res);
    GetSocial(res);
    GetMisc(res);
    GetBirthDate(res);
    GetExperience(res);
    GetEducation(res);
    
    //borrowed from http://jsfiddle.net/koldev/cW7W5/
    var saveData = (function () {
    var a = document.createElement("a");
    document.body.appendChild(a);
    a.style = "display: none";
    return function (data, fileName) {
        var json = data.toJRF();
            blob = new Blob([json], {type: "text/plain"}),
            url = window.URL.createObjectURL(blob);
        a.href = url;
        a.download = fileName;
        a.click();
        window.URL.revokeObjectURL(url);
    };
}());
    saveData(res, "resume.json");
}

function FillForm(evt) {
  var f = evt.target.files[0];

  var reader = new FileReader();

  reader.onload = function(event) {
    var contents = event.target.result;
    var res = new Resume();
    res = res.fromJRF(contents);

    SetName(res);
    SetAddress(res);
    SetPhone(res);
    SetSocial(res);
    SetMisc(res);
    SetBirthDate(res);
    SetExperience(res);
    SetEducation(res);
  }     
  reader.readAsText(f);
}

function SetName(resume) {
    var FullName = resume.getFullName();
    document.getElementsByName('FirstName')[0].value = FullName.FirstName;
    document.getElementsByName('MiddleName')[0].value = FullName.MiddleName;
    document.getElementsByName('LastName')[0].value = FullName.LastName;
}

function SetAddress(resume) {
    var addr = resume.addr.getAddress();
    document.getElementsByName('Street')[0].value = addr.Street;
    document.getElementsByName('City')[0].value = addr.City;
    document.getElementsByName('State')[0].value = addr.State;
    document.getElementsByName('Zip')[0].value = addr.Zip;
    document.getElementsByName('Country')[0].value = addr.Country;
}

function SetPhone(resume) {
    var phone = resume.phone.getPhone();
    document.getElementsByName('Primary')[0].value = phone.Primary;
    document.getElementsByName('Secondary')[0].value = phone.Secondary;
}

function SetSocial(resume) {
    var soc = resume.soc.getSocial();
    document.getElementsByName('Email')[0].value = soc.Email;
    document.getElementsByName('Linkedin')[0].value = soc.LinkedIn;
    document.getElementsByName('Facebook')[0].value = soc.Facebook;
    document.getElementsByName('Twitter')[0].value = soc.Twitter
}

function SetMisc(resume) {
    var misc = resume.misc.getMiscInformation();
    document.getElementsByName('homepage_url')[0].value = misc.Homepage;
    document.getElementsByName('marital')[0].value = misc.MaritalStatus;
    document.getElementsByName('national')[0].value = misc.Nationality;
}

function SetBirthDate(resume) {
    var birthDate = resume.birthDate.getResumeDate();
    document.getElementsByName('month')[0].value = birthDate.Month;
    document.getElementsByName('day')[0].value = birthDate.Day;
    document.getElementsByName('year')[0].value = birthDate.Year;
}

function SetExperience(resume) {
    var exp = resume.getExperienceArray();
    document.getElementsByName('Position')[0].value = exp[0].Position;
    document.getElementsByName('EmployerName')[0].value = exp[0].EmployerName;
    document.getElementsByName('EmployerStreet')[0].value = exp[0].EmployerAddress.Street;
    document.getElementsByName('EmployerCity')[0].value = exp[0].EmployerAddress.City;
    document.getElementsByName('EmployerState')[0].value = exp[0].EmployerAddress.State;
    document.getElementsByName('EmployerZip')[0].value = exp[0].EmployerAddress.Zip;
    document.getElementsByName('EmployerCountry')[0].value = exp[0].EmployerAddress.Country;
    document.getElementsByName('Description')[0].value = exp[0].Description;
    document.getElementsByName('EmployerStartMonth')[0].value = exp[0].StartDate.Month;
    document.getElementsByName('EmployerStartDay')[0].value = exp[0].StartDate.Day;
    document.getElementsByName('EmployerStartYear')[0].value = exp[0].StartDate.Year;
    document.getElementsByName('EmployerEndMonth')[0].value = exp[0].EndDate.Month;
    document.getElementsByName('EmployerEndDay')[0].value = exp[0].EndDate.Day;
    document.getElementsByName('EmployerEndYear')[0].value = exp[0].EndDate.Year;
    if (exp[0].CurrentJob == true) {
        document.getElementsByName('EmployerEndCurrent')[0].checked = true;
    }
    else
        document.getElementsByName('EmployerEndCurrent')[0].checked = false;
}

function SetEducation(resume) {
    var edu = resume.getEducationArray();
    document.getElementsByName('EducationName')[0].value = edu[0].Name;
    document.getElementsByName('EducationStreet')[0].value = edu[0].Address.Street;
    document.getElementsByName('EducationCity')[0].value = edu[0].Address.City;
    document.getElementsByName('EducationState')[0].value = edu[0].Address.State;
    document.getElementsByName('EducationZip')[0].value = edu[0].Address.Zip;
    document.getElementsByName('EducationCountry')[0].value = edu[0].Address.Country;
    document.getElementsByName('EducationStartMonth')[0].value = edu[0].StartDate.Month;
    document.getElementsByName('EducationStartDay')[0].value = edu[0].StartDate.Day;
    document.getElementsByName('EducationStartYear')[0].value = edu[0].StartDate.Year;
    document.getElementsByName('EducationEndMonth')[0].value = edu[0].EndDate.Month;
    document.getElementsByName('EducationEndDay')[0].value = edu[0].EndDate.Day;
    document.getElementsByName('EducationEndYear')[0].value = edu[0].EndDate.Year;
    if (edu[0].CurrentEducation == true) {
        document.getElementsByName('EducationEndCurrent')[0].checked = true;
    }
    else
        document.getElementsByName('EducationEndCurrent')[0].checked = false;
    document.getElementsByName('DegreeName')[0].value = edu[0].DegreeName;
    document.getElementsByName('DegreeGPA')[0].value = edu[0].DegreeGPA;
    if (edu[0].DegreeHonors == true) {
        document.getElementsByName('DegreeHonors')[0].checked = true;
    }
    else
        document.getElementsByName('DegreeHonors')[0].checked = false;
}

function GetName(resume) {
    var FirstName = document.getElementsByName('FirstName')[0].value;
    var MiddleName = document.getElementsByName('MiddleName')[0].value;
    var LastName = document.getElementsByName('LastName')[0].value;
    var FullName = FirstName + ' ' + MiddleName + ' ' + LastName;
    resume.setFullName(FullName);   
}

function GetAddress(resume) {
    resume.addr.setStreet(document.getElementsByName('Street')[0].value);
    resume.addr.setCity(document.getElementsByName('City')[0].value);
    resume.addr.setState(document.getElementsByName('State')[0].value);
    resume.addr.setZip(document.getElementsByName('Zip')[0].value);
    resume.addr.setCountry(document.getElementsByName('Country')[0].value);
}

function GetPhone(resume) {
    resume.phone.setPrimary(document.getElementsByName('Primary')[0].value);
    resume.phone.setSecondary(document.getElementsByName('Secondary')[0].value);
}

function GetSocial(resume) {
    resume.soc.setEmail(document.getElementsByName('Email')[0].value);
    resume.soc.setLinkedIn(document.getElementsByName('Linkedin')[0].value);
    resume.soc.setFacebook(document.getElementsByName('Facebook')[0].value);
    resume.soc.setTwitter(document.getElementsByName('Twitter')[0].value);
}

function GetMisc(resume) {
    resume.misc.setHomepage(document.getElementsByName('homepage_url')[0].value);
    resume.misc.setNationality(document.getElementsByName('national')[0].value);
    resume.misc.setMaritalStatus(document.getElementsByName('marital')[0].value);
}

function GetBirthDate(resume) {
    resume.birthDate.setMonth(document.getElementsByName('month')[0].value);
    resume.birthDate.setDay(document.getElementsByName('day')[0].value);
    resume.birthDate.setYear(document.getElementsByName('year')[0].value);
}

function GetExperience(resume) {
    var exp = resume.newExperience();
    exp.setPosition(document.getElementsByName('Position')[0].value);
    exp.setEmployer(document.getElementsByName('EmployerName')[0].value);
    exp.setStreet(document.getElementsByName('EmployerStreet')[0].value);
    exp.setCity(document.getElementsByName('EmployerCity')[0].value);
    exp.setState(document.getElementsByName('EmployerState')[0].value);
    exp.setZip(document.getElementsByName('EmployerZip')[0].value);
    exp.setCountry(document.getElementsByName('EmployerCountry')[0].value);
    exp.setDescription(document.getElementsByName('Description')[0].value);
    exp.setStartMonth(document.getElementsByName('EmployerStartMonth')[0].value);
    exp.setStartDay(document.getElementsByName('EmployerStartDay')[0].value);
    exp.setStartYear(document.getElementsByName('EmployerStartYear')[0].value);
    exp.setEndMonth(document.getElementsByName('EmployerEndMonth')[0].value);;
    exp.setEndDay(document.getElementsByName('EmployerEndDay')[0].value);
    exp.setEndYear(document.getElementsByName('EmployerEndYear')[0].value);
	if(document.getElementsByName('EmployerEndCurrent')[0].checked == true)
		exp.setCurrentJob(true);
	else
		exp.setCurrentJob(false);
    resume.addExperience(exp)
}


function GetEducation(resume) {
    var edu = resume.newEducation();
    edu.setName(document.getElementsByName('EducationName')[0].value);
    edu.setStreet(document.getElementsByName('EducationStreet')[0].value);
    edu.setCity(document.getElementsByName('EducationCity')[0].value);
    edu.setState(document.getElementsByName('EducationState')[0].value);
    edu.setZip(document.getElementsByName('EducationZip')[0].value);
    edu.setCountry(document.getElementsByName('EducationCountry')[0].value);
    edu.setStartMonth(document.getElementsByName('EducationStartMonth')[0].value);
    edu.setStartDay(document.getElementsByName('EducationStartDay')[0].value);
    edu.setStartYear(document.getElementsByName('EducationStartYear')[0].value);
    edu.setEndMonth(document.getElementsByName('EducationEndMonth')[0].value);
    edu.setEndDay(document.getElementsByName('EducationEndDay')[0].value);
    edu.setEndYear(document.getElementsByName('EducationEndYear')[0].value);
	if(document.getElementsByName('EducationEndCurrent')[0].checked == true)
		edu.setCurrentEducation(true);
	else
		edu.setCurrentEducation(false);
    edu.setDegreeName(document.getElementsByName('DegreeName')[0].value);
    edu.setDegreeGPA(document.getElementsByName('DegreeGPA')[0].value);
	if(document.getElementsByName('DegreeHonors')[0].checked == true)
		edu.setDegreeHonors(true);
	else
		edu.setDegreeHonors(false);
    resume.addEducation(edu);
}

function clearForm() {
    var elements = document.getElementsByTagName("input");
    for (var i = 0; i < elements.length; i++) {
        if(elements[i].type == "text") {
            elements[i].value = "";
        }
        if(elements[i].type == "checkbox") {
            elements[i].checked = false;
        }
        if(elements[i].type == "number") {
            elements[i].value = "text";
        }
    }
}

function testForm() {
  clearForm();
  var res = new Resume();
  var jRes;
  var jNewRes;
    
  this.testFirstName = function() {
    res.fullName.setFirstName("Barry");
    res.fullName.setMiddleName("Henry");
    res.fullName.setLastName("Allen");
  }

  this.testAddress = function() {
    res.addr.setStreet("1234 Main Street");
    res.addr.setCity("Central City");
    res.addr.setState("MO");
    res.addr.setZip("12345");
    res.addr.setCountry("United States");
  }

  this.testPhone = function() {
    res.phone.setPrimary("(700) 555-1234");
    res.phone.setSecondary("(700) 555-4321");
  }

  this.testSocial = function() {
    res.soc.setEmail("ballen@ccpd.org");
    res.soc.setLinkedIn("linkedin.com/barryallen");
    res.soc.setFacebook("facebook.com/barryallen");
    res.soc.setTwitter("@barryallen");
  }

  this.testMisc = function() {
    res.misc.setHomepage("www.barryallen.com");
    res.misc.setNationality("American");
    res.misc.setMaritalStatus("single");
  }

  this.testBirthDate = function() {
    res.birthDate.setMonth("March");
    res.birthDate.setDay("19");
    res.birthDate.setYear("1995");
  }

  this.testExperience = function() {
    var exp = res.newExperience();
    exp.setPosition("Forensic Scientest");
    exp.setEmployer("Central City Police Department");
    exp.setStreet("4321 Main Street");
    exp.setCity("Central City");
    exp.setState("MO");
    exp.setZip("12345");
    exp.setCountry("United States");
    exp.setDescription("Solved all the cases");
    exp.setStartMonth("June");
    exp.setStartDay("23");
    exp.setStartYear("2006");
    exp.setEndMonth("March");
    exp.setEndDay("3");
    exp.setEndYear("2015");
    exp.setCurrentJob(true);
    res.addExperience(exp);
  }

  this.testEducation = function() {
    var edu = res.newEducation();
    edu.setName("Central City College");
    edu.setStreet("666 Main Street");
    edu.setCity("Central City");
    edu.setState("MO");
    edu.setZip("12345");
    edu.setCountry("United States");
    edu.setStartMonth("June");
    edu.setStartDay("23");
    edu.setStartYear("2002");
    edu.setEndMonth("March");
    edu.setEndDay("3");
    edu.setEndYear("2006");
    edu.setCurrentEducation(false);
    edu.setDegreeName("Bachelors of Forensic Science");
    edu.setDegreeGPA("4.0");
    edu.setDegreeHonors(true);
    res.addEducation(edu);
  }
  
  this.run = function() {
	this.testFirstName();
    this.testAddress();
    this.testPhone();
    this.testSocial();
    this.testMisc();
    this.testBirthDate();
    this.testExperience();
    this.testEducation();
    SetName(res);
    SetAddress(res);
    SetPhone(res);
    SetSocial(res);
    SetMisc(res);
    SetBirthDate(res);
    SetExperience(res);
    SetEducation(res);

	var newRes = new Resume();
	GetName(newRes);
    GetAddress(newRes);
    GetPhone(newRes);
    GetSocial(newRes);
    GetMisc(newRes);
    GetBirthDate(newRes);
    GetExperience(newRes);
    GetEducation(newRes);
	var jRes = res.toJRF();
	var jNewRes = newRes.toJRF();
	assertEqual(jRes, jNewRes);
  }
  
  console.log("Form test passed");
}

function launchTestForm() {
    var formfilltest = new testForm();
    formfilltest.run();
}

//END OF OUR SECTION

// function readFile(evt) {
  // var f = evt.target.files[0];

  // var reader = new FileReader();

  // reader.onload = function(event) {
    // var contents = event.target.result;
    // var res = new Resume();
    // res = res.fromJRF(contents);

    // var link = document.getElementById("downloadLink");
    // link.href = makeTextFile(res.toJRF());
    // link.style.display = "block";

    // document.getElementById("container").innerHTML = res.JRF_HTML();
  // }

  // reader.readAsText(f);
// }

function makeTextFile(text) {
  var data = new Blob([text], {type: 'text/plain'});

  textFile = window.URL.createObjectURL(data);

  return textFile;
}

document.addEventListener("DOMContentLoaded", function(event) {
  document.getElementById('id_file').addEventListener('change', FillForm, false);
});

function Address() {
  this.Street = "";
  this.City = "";
  this.State = "";
  this.Zip = "";
  this.Country = "";

  this.getAddress = function() {
    return this;
  }

  this.setStreet = function(street) {
    this.Street = street;
  }

  this.setCity = function(city) {
    this.City = city;
  }

  this.setState = function(state) {
    this.State = state;
  }

  this.setZip = function(zip) {
    this.Zip = zip;
  }

  this.setCountry = function(country) {
    this.Country = country;
  }
}

function Social() {
  this.Email = "";
  this.LinkedIn = "";
  this.Facebook = "";
  this.Twitter = "";

  this.getSocial = function() {
    return this;
  }

  this.setEmail = function(email) {
    this.Email = email;
  }

  this.setLinkedIn = function(linkedIn) {
    this.LinkedIn = linkedIn;
  }

  this.setFacebook = function(facebook) {
    this.Facebook = facebook;
  }

  this.setTwitter = function(twitter) {
    this.Twitter = twitter;
  }
}

function ResumeDate() {
  this.Month = "";
  this.Day = "";
  this.Year = "";

  this.getResumeDate = function() {
    return this;
  }
  
  this.setMonth = function(month) {
    this.Month = month;
  }

  this.setDay = function(day) {
    this.Day = day;
  }

  this.setYear = function(year) {
    this.Year = year;
  }
}

function Photo() {
  this.PhotoSource = "";
  this.PhotoData = "";

  this.PhotoSize = {};
  this.PhotoSize['Height'] = "";
  this.PhotoSize['Width'] = "";

  this.PhotoLoc = {};
  this.PhotoLoc['X'] = "";
  this.PhotoLoc['Y'] = "";

  this.getPhoto = function() {
    return this;
  }

  this.setPhotoSource = function(photoSource) {
    this.PhotoSource = photoSource;
  }

  this.setPhotoData = function(photoData) {
    this.PhotoData = photoData;
  }

  this.setPhotoSize = function(height, width) {
    this.PhotoSize = {'Height': height, 'Width': width};
  }

  this.setPhotoLoc = function(x, y) {
    this.PhotoLoc = {'X': x, 'Y': y};
  }
}

function Phone() {
  this.Primary = "";
  this.Secondary = "";

  this.getPhone = function() {
    return this;
  }

  this.setPrimary = function(primary) {
    this.Primary = primary;
  }

  this.setSecondary = function(secondary) {
    this.Secondary = secondary;
  }
}

function FullName() {
  this.FirstName = "";
  this.MiddleName = "";
  this.LastName = "";

  this.getFullName = function() {
    return this;
  }

  this.setFirstName = function(name) {
    this.FirstName = name;
  }

  this.setMiddleName = function(name) {
    this.MiddleName = name;
  }

  this.setLastName = function(name) {
    this.LastName = name;
  }
}

function Experience() {
  this.Position = "";

  this.EmployerName = "";
  this.EmployerAddress = new Address();

  this.Description = "";
  this.StartDate = new ResumeDate();

  this.EndDate = new ResumeDate();
  this.CurrentJob = false;

  this.getExperience = function() {
    return this;
  }

  this.setPosition = function(position) {
    this.Position = position;
  }

  this.setEmployer = function(name) {
    this.EmployerName = name;
  }

  this.setStreet = function(street) {
    this.EmployerAddress.setStreet(street);
  }

  this.setCity = function(city) {
    this.EmployerAddress.setCity(city);
  }

  this.setState = function(state) {
    this.EmployerAddress.setState(state);
  }

  this.setZip = function(zip) {
    this.EmployerAddress.setZip(zip);
  }

  this.setCountry = function(country) {
    this.EmployerAddress.setCountry(country);
  }

  this.setDescription = function(description) {
    this.Description = description;
  }

  this.setStartMonth = function(month) {
    this.StartDate.setMonth(month);
  }

  this.setStartDay = function(day) {
    this.StartDate.setDay(day);
  }

  this.setStartYear = function(year) {
    this.StartDate.setYear(year);
  }

  this.setEndMonth = function(month) {
    this.EndDate.setMonth(month);
  }

  this.setEndDay = function(day) {
    this.EndDate.setDay(day);
  }


  this.setEndYear = function(year) {
    this.EndDate.setYear(year);
  }

  this.setCurrentJob = function(isCurrent) {
    this.CurrentJob = isCurrent;
  }
}

function Education() {
  this.Name = "";
  this.Address = new Address();

  this.StartDate = new ResumeDate();

  this.EndDate = new ResumeDate();
  this.CurrentEducation = false;

  this.DegreeName = "";
  this.DegreeGPA = 0.0;
  this.DegreeHonors = false;

  this.getEducation = function() {
    return this;
  }

  this.setName = function(name) {
    this.Name = name;
  }

  this.setStreet = function(street) {
    this.Address.setStreet(street);
  }

  this.setCity = function(city) {
    this.Address.setCity(city);
  }

  this.setState = function(state) {
    this.Address.setState(state);
  }

  this.setZip = function(zip) {
    this.Address.setZip(zip);
  }

  this.setCountry = function(country) {
    this.Address.setCountry(country);
  }

  this.setStartMonth = function(month) {
    this.StartDate.setMonth(month);
  }

  this.setStartDay = function(day) {
    this.StartDate.setDay(day);
  }

  this.setStartYear = function(year) {
    this.StartDate.setYear(year);
  }

  this.setEndMonth = function(month) {
    this.EndDate.setMonth(month);
  }

  this.setEndDay = function(day) {
    this.EndDate.setDay(day);
  }

  this.setEndYear = function(year) {
    this.EndDate.setYear(year);
  }

  this.setCurrentEducation = function(isCurrent) {
    this.CurrentEducation = isCurrent;
  }

  this.setDegreeName = function(name) {
    this.DegreeName = name;
  }

  this.setDegreeGPA = function(gpa) {
    this.DegreeGPA = gpa;
  }

  this.setDegreeHonors = function(isHonors) {
    this.DegreeHonors = isHonors;
  }
}

function MiscInformation() {
  this.Homepage = "";
  this.Nationality = "";
  this.MaritalStatus = "";

  this.getMiscInformation = function() {
    return this;
  }

  this.setHomepage = function(homepage) {
    this.Homepage = homepage;
  }

  this.setNationality = function(nationality) {
    this.Nationality = nationality;
  }

  this.setMaritalStatus = function(maritalStatus) {
    this.MaritalStatus = maritalStatus;
  }
}

function Resume() {
  this.fullName = new FullName();

  this.addr = new Address();

  this.phone = new Phone();

  this.soc = new Social();

  this.misc = new MiscInformation();

  this.birthDate = new ResumeDate();

  this.photo = new Photo();

  this.experience = [];

  this.education = [];

  this.setFullName = function(name) {
    tempArr = name.split(' ');
    this.fullName.FirstName = tempArr[0];
    this.fullName.MiddleName = tempArr[1];
    this.fullName.LastName = tempArr[2];
  }

  this.getFullName = function() {
    return this.fullName.getFullName();
  }

  this.newEducation = function() {
    return new Education();
  }

  this.addEducation = function(edu) {
    this.education.push(edu);
  }

  this.getEducationArray = function() {
    return this.education;
  }

  this.newExperience = function() {
    return new Experience();
  }

  this.addExperience = function(exp) {
    this.experience.push(exp);
  }

  this.getExperienceArray = function() {
    return this.experience;
  }

  this.toJRF = function() {
    return JSON.stringify(this, null, "\t")
  }

  this.fromJRF = function(json) {
    var res = new Resume();
    obj = JSON.parse(json);
    //copy address
    for(var key in obj.addr) {
      res.addr[key] = obj.addr[key];
    }

    //copy birthDate
    for(var key in obj.birthDate) {
      res.birthDate[key] = obj.birthDate[key];
    }

    //copy education
    for(var i = 0; i < obj.education.length; i++) {
      edu = res.newEducation();
      edu.setName(obj.education[i].Name);
      edu.setStreet(obj.education[i].Address.Street);
      edu.setCity(obj.education[i].Address.City);
      edu.setState(obj.education[i].Address.State);
      edu.setZip(obj.education[i].Address.Zip);
      edu.setCountry(obj.education[i].Address.Country);
      edu.setStartMonth(obj.education[i].StartDate.Month);
      edu.setStartDay(obj.education[i].StartDate.Day);
      edu.setStartYear(obj.education[i].StartDate.Year);
      edu.setEndMonth(obj.education[i].EndDate.Month);
      edu.setEndDay(obj.education[i].EndDate.Day);
      edu.setEndYear(obj.education[i].EndDate.Year);
      edu.setCurrentEducation(obj.education[i].CurrentEducation);
      edu.setDegreeName(obj.education[i].DegreeName);
      edu.setDegreeGPA(obj.education[i].DegreeGPA);
      edu.setDegreeHonors(obj.education[i].DegreeHonors);
      res.addEducation(edu);
    }

    //copy experience
    for(var i = 0; i < obj.experience.length; i++) {
      exp = res.newExperience();
      exp.setPosition(obj.experience[i].Position);
      exp.setEmployer(obj.experience[i].EmployerName);
      exp.setStreet(obj.experience[i].EmployerAddress.Street);
      exp.setCity(obj.experience[i].EmployerAddress.City);
      exp.setState(obj.experience[i].EmployerAddress.State);
      exp.setZip(obj.experience[i].EmployerAddress.Zip);
      exp.setCountry(obj.experience[i].EmployerAddress.Country);
      exp.setDescription(obj.experience[i].Description);
      exp.setStartMonth(obj.experience[i].StartDate.Month);
      exp.setStartDay(obj.experience[i].StartDate.Day);
      exp.setStartYear(obj.experience[i].StartDate.Year);
      exp.setEndMonth(obj.experience[i].EndDate.Month);
      exp.setEndDay(obj.experience[i].EndDate.Day);
      exp.setEndYear(obj.experience[i].EndDate.Year);
      exp.setCurrentJob(obj.experience[i].CurrentJob);
      res.addExperience(exp);
    }

    //copy fullName
    for(var key in obj.fullName) {
      res.fullName[key] = obj.fullName[key];
    }

    //copy misc
    for(var key in obj.misc) {
      res.misc[key] = obj.misc[key];
    }

    //copy phone
    for(var key in obj.phone) {
      res.phone[key] = obj.phone[key];
    }

    //copy photo
    for(var key in obj.photo) {
      res.photo[key] = obj.photo[key];
    }

    //copy soc
    for(var key in obj.soc) {
      res.soc[key] = obj.soc[key];
    }

    return res;
  }

  this.JRF_HTML = function() {
    var str = "";

    var fullname = this.getFullName();

    //Header - fullname
    str += "<h1 id=\"fullname\">" + fullname.FirstName + " " + fullname.MiddleName + " " +
    fullname.LastName + "</h1>";

    var phone = this.phone.getPhone();
    //Contact information
    str += "<hr><h3>Contact Information</h3>";
    str += "<div id=\"primary\">Primary: " + phone.Primary + "</div>";
    str += "<div id=\"secondary\">Secondary: " + phone.Secondary + "</div><br>";

    var addr = this.addr.getAddress();
    str += "<div id=\"address\">";
    str += "<div id=\"street\">" + addr.Street + "</div>";
    str += "<div id=\"citystatezip\">" + addr.City + ", " + addr.State + " " + addr.Zip + "</div>";
    str += "<div id=\"country\">" + addr.Country + "</div>";
    str += "</div>";
    str +=  "<hr>";

    var exp = this.getExperienceArray();
    str += "<div id=\"experience\"><h3>Experience</h3>";
    for(var i = 0; i < exp.length; i++) {
      str += "<strong><div id=\"employer\">" + exp[i].EmployerName + "</div></strong>";
      str += "<div id=\"title\">" + exp[i].Position + "</div>";
      str += "<div id=\"desc\">" + exp[i].Description + "</div>";
      str += "<div id=\"exp_citystatezip\">" + exp[i].EmployerAddress.City + ", " +
      exp[i].EmployerAddress.State + " " + exp[i].EmployerAddress.Zip + "</div>";
      str += "<div id=\"exp_dates\">" + exp[i].StartDate.Month + " " + exp[i].StartDate.Year + " - " +
      exp[i].EndDate.Month + " " + exp[i].EndDate.Year + "</div>";
    }
    str += "</div>";
    str +=  "<hr>";

    var edu = this.getEducationArray();
    str += "<div id=\"education\"><h3>Education</h3>";
    for(var i = 0; i < edu.length; i++) {
      str += "<strong><div id=\"ed_name\">" + edu[i].Name + "</div></strong>";
      str += "<div id=\"ed_citystatezip\">" + edu[i].Address.City + ", " + 
      edu[i].Address.State + " " + edu[i].Address.Zip + "</div>";
      str += "<div id=\"edu_dates\">" + edu[i].StartDate.Month + " " + edu[i].StartDate.Year + " - " +
      edu[i].EndDate.Month + " " + edu[i].EndDate.Year + "</div>";
      str += "<div id=\"degreeName\">" + edu[i].DegreeName + "</div>";
      str += "<div id=\"gpa\">" + edu[i].DegreeGPA + " GPA</div>";
    }

    str += "</div>";
    str +=  "<hr>";

    var soc = this.soc.getSocial();
    str += "<div id=\"social\"><h3>Links</h3>";
    str += "<div id=\"email\">Email: " + soc.Email + "</div>";
    str += "<div id=\"facebook\">Facebook: " + soc.Facebook + "</div>";
    str += "<div id=\"linkedin\">LinkedIn: " + soc.LinkedIn + "</div>";
    str += "<div id=\"twitter\">Twitter: " + soc.Twitter + "</div>";
    str += "</div>";

    return str;
  }
}

function assertEqual(first, second) {
  if (first !== second) {
    throw first + " not equal to " + second;
  }
}

function TestJRF() {
  var res = new Resume();
  var jsonRes;

  this.testFirstName = function() {
    res.fullName.setFirstName("Barry");
    res.fullName.setMiddleName("Henry");
    res.fullName.setLastName("Allen");

    var fullname = res.getFullName();

    assertEqual(fullname.FirstName, "Barry");
    assertEqual(fullname.MiddleName, "Henry");
    assertEqual(fullname.LastName, "Allen");
  }

  this.testAddress = function() {
    res.addr.setStreet("1234 Main Street");
    res.addr.setCity("Central City");
    res.addr.setState("MO");
    res.addr.setZip("12345");
    res.addr.setCountry("United States");

    var addr = res.addr.getAddress();

    assertEqual(addr.Street, "1234 Main Street");
    assertEqual(addr.City, "Central City");
    assertEqual(addr.State, "MO");
    assertEqual(addr.Zip, "12345");
    assertEqual(addr.Country, "United States");
  }

  this.testPhone = function() {
    res.phone.setPrimary("(700) 555-1234");
    res.phone.setSecondary("(700) 555-4321");

    var phone = res.phone.getPhone();

    assertEqual(phone.Primary, "(700) 555-1234");
    assertEqual(phone.Secondary, "(700) 555-4321");
  }

  this.testSocial = function() {
    res.soc.setEmail("ballen@ccpd.org");
    res.soc.setLinkedIn("linkedin.com/barryallen");
    res.soc.setFacebook("facebook.com/barryallen");
    res.soc.setTwitter("@barryallen");

    var social = res.soc.getSocial();

    assertEqual(social.Email, "ballen@ccpd.org");
    assertEqual(social.LinkedIn, "linkedin.com/barryallen");
    assertEqual(social.Facebook, "facebook.com/barryallen");
    assertEqual(social.Twitter, "@barryallen");
  }

  this.testMisc = function() {
    res.misc.setHomepage("www.barryallen.com");
    res.misc.setNationality("American");
    res.misc.setMaritalStatus("single");

    var miscInfo = res.misc.getMiscInformation();

    assertEqual(miscInfo.Homepage, "www.barryallen.com");
    assertEqual(miscInfo.Nationality, "American");
    assertEqual(miscInfo.MaritalStatus, "single");
  }

  this.testBirthDate = function() {
    res.birthDate.setMonth("March");
    res.birthDate.setDay("19");
    res.birthDate.setYear("1995");

    var birthdate = res.birthDate.getResumeDate();

    assertEqual(birthdate.Month, "March");
    assertEqual(birthdate.Day, "19");
    assertEqual(birthdate.Year, "1995");
  }

  this.testExperience = function() {
    var exp = res.newExperience();
    exp.setPosition("Forensic Scientest");
    exp.setEmployer("Central City Police Department");
    exp.setStreet("4321 Main Street");
    exp.setCity("Central City");
    exp.setState("MO");
    exp.setZip("12345");
    exp.setCountry("United States");
    exp.setDescription("Solved all the cases");
    exp.setStartMonth("June");
    exp.setStartDay("23");
    exp.setStartYear("2006");
    exp.setEndMonth("March");
    exp.setEndDay("3");
    exp.setEndYear("2015");
    exp.setCurrentJob(true);
    res.addExperience(exp);

    var experience = res.getExperienceArray();

    assertEqual(experience[0].Position, "Forensic Scientest");
    assertEqual(experience[0].EmployerName, "Central City Police Department");
    assertEqual(experience[0].EmployerAddress.Street, "4321 Main Street");
    assertEqual(experience[0].EmployerAddress.City, "Central City");
    assertEqual(experience[0].EmployerAddress.State, "MO");
    assertEqual(experience[0].EmployerAddress.Zip, "12345");
    assertEqual(experience[0].EmployerAddress.Country, "United States");
    assertEqual(experience[0].Description, "Solved all the cases");
    assertEqual(experience[0].StartDate.Month, "June");
    assertEqual(experience[0].StartDate.Day, "23");
    assertEqual(experience[0].StartDate.Year, "2006");
    assertEqual(experience[0].EndDate.Month, "March");
    assertEqual(experience[0].EndDate.Day, "3");
    assertEqual(experience[0].EndDate.Year, "2015");
    assertEqual(experience[0].CurrentJob, true);
  }

  this.testEducation = function() {
    var edu = res.newEducation();
    edu.setName("Central City College");
    edu.setStreet("666 Main Street");
    edu.setCity("Central City");
    edu.setState("MO");
    edu.setZip("12345");
    edu.setCountry("United States");
    edu.setStartMonth("June");
    edu.setStartDay("23");
    edu.setStartYear("2002");
    edu.setEndMonth("March");
    edu.setEndDay("3");
    edu.setEndYear("2006");
    edu.setCurrentEducation(false);
    edu.setDegreeName("Bachelors of Forensic Science");
    edu.setDegreeGPA("4.0");
    edu.setDegreeHonors(true);
    res.addEducation(edu);

    var education = res.getEducationArray();

    assertEqual(education[0].Name, "Central City College");
    assertEqual(education[0].Address.Street, "666 Main Street");
    assertEqual(education[0].Address.City, "Central City");
    assertEqual(education[0].Address.State, "MO");
    assertEqual(education[0].Address.Zip, "12345");
    assertEqual(education[0].Address.Country, "United States");
    assertEqual(education[0].StartDate.Month, "June");
    assertEqual(education[0].StartDate.Day, "23");
    assertEqual(education[0].StartDate.Year, "2002");
    assertEqual(education[0].EndDate.Month, "March");
    assertEqual(education[0].EndDate.Day, "3");
    assertEqual(education[0].EndDate.Year, "2006");
    assertEqual(education[0].CurrentEducation, false);
    assertEqual(education[0].DegreeName, "Bachelors of Forensic Science");
    assertEqual(education[0].DegreeGPA, "4.0");
    assertEqual(education[0].DegreeHonors, true);
  }

  this.testToJRF = function() {
    jsonRes = res.toJRF();
    assertEqual(jsonRes, JSON.stringify(res, null, '\t'));
  }

  this.run = function() {
    this.testFirstName();
    this.testAddress();
    this.testPhone();
    this.testSocial();
    this.testMisc();
    this.testBirthDate();
    this.testExperience();
    this.testEducation();
    this.testToJRF();

    console.log("All tests passed.");
  }
}

//var unit_tests = new TestJRF();
//unit_tests.run();
