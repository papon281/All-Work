
function success(email, password){
    if(!isEmail(email)){
        alert("Invalid email");
        return;
    }
    if(email == "papon@gmail.com" && password == "pass1234"){
        console.log("In success");
        location.href = "success.html";
    } else {
        console.log("In failure");
        location.href = "error.html";
    }
}

function isEmail(email){
    const regex = /^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$/;
    return regex.test(email);
}