// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.7.0 <0.9.0;

contract SendMoney {
    function receiveMoney() public payable {}

    function getBalance() public view returns(uint) {
        return address(this).balance;
    }

    function withdrawAll() public{
        this.donateAllTo(payable(msg.sender));
    }

    function withdrawAmount(uint num_wei) public{
        this.donateTo(payable(msg.sender), num_wei);
    }

    function withdrawPercent(uint percent) public{
        address payable to = payable(msg.sender);
        if(percent > 0 && percent <= 100) {
            uint amount = this.getBalance()/100 * percent;
            to.transfer(amount);
        }
    }

    function donateAllTo(address payable to) public{
        this.donateTo(to, this.getBalance());
    }

    function donateTo(address payable to, uint num_wei) public{
        if(this.getBalance() > num_wei){
            to.transfer(num_wei);
        } else {
            to.transfer(this.getBalance());
        }
    }
}