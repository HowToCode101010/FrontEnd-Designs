<template lang="">
    <section id="contact" class="py-16">
        <div class="container mx-auto px-4">
            <h2 class="text-3xl font-bold mb-6 text-center underline">Contact</h2>
            <form class="max-w-md mx-auto space-y-4">
                <input type="text" placeholder="Your Name" class="w-full p-3 border rounded-md">
                <input type="email" placeholder="Your Email" class="w-full p-3 border rounded-md">
                <textarea placeholder="Your Message..." class="w-full p-3 border rounded-md h-32"></textarea>
                <button type="submit" class="contact-button w-full bg-blue-800 text-white p-3 rounded-md hover:bg-blue-600 transition-colors">Send Message</button>
            </form>
        </div>
    </section>
</template>
<script setup>

</script>
<style>
.contact-button{
    background-color: rgb(30 64 175)
}
.contact-button:hover{
    background-color: rgb(37 99 235);
}
</style>
