import axios from 'axios'

// Build a unical instance of axios for store request
const HTTP = axios.create({
  baseURL: process.env.VUE_APP_API_URL || 'http://192.168.99.101:1337/',
  headers: {
    'Authorization': {
      toString () {
        return `Bearer ${localStorage.getItem('user-token')}`
      }
    }
  }
})

export default HTTP
