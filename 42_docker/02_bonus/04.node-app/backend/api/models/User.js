/*****************************************
*               USER Model              *
*        Contains all user records       *
*****************************************/

module.exports = {

  tableName: 'user',

  attributes: {

    //  ╔═╗╦═╗╦╔╦╗╦╔╦╗╦╦  ╦╔═╗╔═╗
    //  ╠═╝╠╦╝║║║║║ ║ ║╚╗╔╝║╣ ╚═╗
    //  ╩  ╩╚═╩╩ ╩╩ ╩ ╩ ╚╝ ╚═╝╚═╝

    emailAddress: {
      type: 'string',
      required: true,
      unique: true,
      isEmail: true,
      maxLength: 200,
      example: 'carol.reynard@microsoft.com',
      description: 'Email address of the user.'
    },

    encryptedPassword: {
      type: 'string',
      required: true,
      protect: true,
      maxLength: 200,
      example: '2$28a8eabna301089103-13948134nad',
      description: 'Securely hashed representation of the user\'s login password.'
    },

    fullName: {
      type: 'string',
      required: true,
      maxLength: 35,
      example: 'Lisa Microwave van der Jenny',
      description: 'The user\'s fisrt name'
    }

    //  ╔═╗╔═╗╔═╗╔═╗╔═╗╦╔═╗╔╦╗╦╔═╗╔╗╔╔═╗
    //  ╠═╣╚═╗╚═╗║ ║║  ║╠═╣ ║ ║║ ║║║║╚═╗
    //  ╩ ╩╚═╝╚═╝╚═╝╚═╝╩╩ ╩ ╩ ╩╚═╝╝╚╝╚═╝


  },

  // Return a shallow copy of this record with certain attributes removed at each request
  customToJSON () {
    return _.omit(this, ['encryptedPassword']);
  }
};
