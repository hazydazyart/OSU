function readFile(evt) {
  var f = evt.target.files[0];

  var reader = new FileReader();

  reader.onload = function(event) {
    var contents = event.target.result;
    var res = new Resume();
    res = res.fromJRF(contents);

    var link = document.getElementById("downloadLink");
    link.href = makeTextFile(res.toJRF());
    link.style.display = "block";

    //console.log(res);
    document.getElementById("container").innerHTML = res.JRF_HTML();
    //console.log(res.fromJRF(contents));
  }

  reader.readAsText(f);
}

function makeTextFile(text) {
  var data = new Blob([text], {type: 'text/plain'});

  textFile = window.URL.createObjectURL(data);

  return textFile;
}

document.addEventListener("DOMContentLoaded", function(event) {
  document.getElementById('id_file').addEventListener('change', readFile, false);
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
    this.Country = country;
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
      exp.setCountry(obj.experience[i].Country);
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

var res = new Resume();

// Test setters
res.fullName.setFirstName("Barry");
res.fullName.setMiddleName("Henry");
res.fullName.setLastName("Allen");

res.addr.setStreet("1234 Main Street");
res.addr.setCity("Central City");
res.addr.setState("MO");
res.addr.setZip("12345");
res.addr.setCountry("United States");

res.phone.setPrimary("(700) 555-1234");
res.phone.setSecondary("(700) 555-4321");

res.soc.setEmail("ballen@ccpd.org");
res.soc.setLinkedIn("linkedin.com/barryallen");
res.soc.setFacebook("facebook.com/barryallen");
res.soc.setTwitter("@barryallen");

res.misc.setHomepage("www.barryallen.com");
res.misc.setNationality("American");
res.misc.setMaritalStatus("single");

res.birthDate.setMonth("March");
res.birthDate.setDay("19");
res.birthDate.setYear("1995");

exp = res.newExperience();
exp.setPosition("Forensic Scientiest");
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

edu = res.newEducation();
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

// Test getters
console.log("----");
console.log(res.fullName.getFullName());
console.log("----");
console.log(res.addr.getAddress());
console.log("----");
console.log(res.phone.getPhone());
console.log("----");
console.log(res.soc.getSocial());
console.log("----");
console.log(res.misc.getMiscInformation());
console.log("----");
console.log(res.birthDate.getResumeDate());
console.log("----");
console.log(res.photo.getPhoto());
console.log("----");
console.log(res.getExperienceArray());
console.log("----");
console.log(res.getEducationArray());
console.log("----");
console.log(res);
