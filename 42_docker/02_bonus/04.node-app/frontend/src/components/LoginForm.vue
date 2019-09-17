<template>
  <v-layout row wrap align-center justify-center fill-height>
    <v-spacer />
    <v-flex text-xs-center>
      <v-form ref="form" @submit.prevent="login">

        <v-flex pb-4>
          <h2 class="primary--text">
            Connexion
          </h2>
        </v-flex>

        <v-flex v-if="isError" pb-2>
          <v-alert :value="isError" type="error" outline>
            Erreur d'authentification
          </v-alert>
        </v-flex>

        <v-flex>
          <v-text-field
            color="primary"
            :loading="isLoading"
            label="Adrese email"
            v-model="loginData.emailAddress"
            v-validate="'required|email'"
            data-vv-name="email"
            :error-messages="errors.collect('email')"
            box
           ></v-text-field>
        </v-flex>

        <v-flex>
          <v-text-field
            color="primary"
            :loading="isLoading"
            label="Mot de passe"
            v-model="loginData.password"
            v-validate="'required'"
            data-vv-name="password"
            :error-messages="errors.collect('password')"
            :append-icon="show1 ? 'visibility_off' : 'visibility'"
            :type="show1 ? 'text' : 'password'"
            @click:append="show1 = !show1"
            box
          ></v-text-field>
        </v-flex>

        <v-flex text-xs-center>
          <v-btn large color="primary" :disabled="!isComplete" class="text-none" type="submit">
            Me connecter
          </v-btn>
        </v-flex>

      </v-form>
    </v-flex>
    <v-spacer/>
  </v-layout>
</template>

<script>
import { AUTH_REQUEST } from '@/store/modules/entrance/actions/entrance.actions'

export default {
  name: 'Login',
  data () {
    return {
      loginData: {
        emailAddress: '',
        password: ''
      },
      isLoading: false,
      show1: false,
      isError: false
    }
  },
  methods: {
    login () {
      this.isLoading = true
      this.$store.dispatch(AUTH_REQUEST, this.loginData)
        .then(() => this.loginSucceed())
        .catch(() => this.loginFailed())
    },
    loginSucceed () {
      this.isLoading = false
      this.$router.push({ name: 'Private' })
    },
    loginFailed () {
      this.isError = true
      this.isLoading = false
      this.loginData.password = ''
    }
  },
  computed: {
    isComplete () {
      return this.loginData.emailAddress && this.loginData.password && (!this.errors.items[0])
    }
  }
}
</script>
